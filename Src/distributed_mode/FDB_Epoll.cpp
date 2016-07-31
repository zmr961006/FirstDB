//
// Created by butter on 16-7-26.
//

#include "FDB_Epoll.h"
#include "FDB_Accept.h"
#include "FDB_Users.h"
#include "FDB_Users.h"
#include <iostream>

//extern FDB_Users user;
FDB_Users user;

FDB_Epoll::FDB_Epoll(int fd) {                                              /*构造函数*/

    m_iListen_fd = fd;                                                      /*初始化m_iSock_fd*/
    m_iEpoll_fd = epoll_create(m_ciMAX_NUM);                                /*创建epoll实例*/
    Epoll_create_events();                                                  /*开辟epoll_event空间*/

    if( -1 == m_iEpoll_fd)
        std::cout << "epoll_create ERROR! "<< std::endl;


}


bool FDB_Epoll::Epoll_create_events() {

    m_epEvent_p = new epoll_event[m_ciMAX_NUM];                            /*开辟epoll_event空间*/

    if( !m_epEvent_p ) {
        std::cout << "new error go to log now! " << std::endl;
        return false;
    }

    return true;

}



bool FDB_Epoll::Epoll_add_initListen(int fd, bool enable_et){

    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;

    if(enable_et) {
        event.events |= EPOLLET;
        /*event.events |= EPOLLONESHOT;*/
    }
    epoll_ctl(m_iEpoll_fd, EPOLL_CTL_ADD, fd, &event);                      /*向兴趣列表里添加监听事件*/
    return true;

}


bool FDB_Epoll::Epoll_add(int fd, bool enable_et, bool oneshot) {

    std::cout << "one shot!" << std::endl;
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;

    if( enable_et ) {
        event.events |= EPOLLET;                                            /*设置边沿触发*/
    }

    if(oneshot) {
        event.events |= EPOLLONESHOT;                                       /*只处理一次*/
    }

    epoll_ctl(m_iEpoll_fd, EPOLL_CTL_ADD, fd, &event);                      /*添加*/
    Epoll_setnoblocking(fd);

    return true;

}


bool FDB_Epoll::Epoll_setnoblocking(int fd) {

    int old_option = fcntl(fd, F_GETFL);
    int new_option = old_option | O_NONBLOCK;

    fcntl(fd, F_SETFL, new_option);                                         /*设置非阻塞*/
    return (bool)old_option;

}

bool FDB_Epoll::Epoll_reset(int fd) {

    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
    epoll_ctl(m_iEpoll_fd, EPOLL_CTL_MOD, fd, &event);                      /*重置读事件，边沿触发， 处理一次*/

}

bool FDB_Epoll::Epoll_del(int fd) {

    epoll_event event;
    event.data.fd = fd;
    epoll_ctl(m_iEpoll_fd, EPOLL_CTL_DEL, fd, &event);                      /*删除*/
    close(fd);

}

bool FDB_Epoll::Epoll_wait() {                                              /*epoll_wait()服务器核心*/

    bool work_status = true;
    Epoll_add_initListen(m_iListen_fd, false);

    while(work_status)
    {
        std::cout << "Debug_message: Showing On Line List ! " << std::endl;

        user.User_show();


        std::cout << "Debug_message: epoll waiting" << std::endl;
        int ep_event_num = epoll_wait(m_iEpoll_fd, m_epEvent_p, m_ciMAX_NUM, -1); /*调用epoll_wait() 核心函数*/
        assert(ep_event_num >= 0);

        for(int ep_event_i = 0; ep_event_i < ep_event_num; ep_event_i++) {

            int now_skfd = m_epEvent_p[ep_event_i].data.fd;
            int accepted_fd;

            if( (  m_epEvent_p[ep_event_i].events & EPOLLERR) ||
                (  m_epEvent_p[ep_event_i].events & EPOLLHUP) ||
                (!(m_epEvent_p[ep_event_i].events & EPOLLIN )) ) {          /*error，挂起，断开，并且没有发生读事件*/

                std::cout << "Debug_message: epoll Error!" << std::endl;
                Epoll_del(now_skfd);

                continue;

            }else if(now_skfd == m_iListen_fd &&
                    (m_epEvent_p[ep_event_i].events & EPOLLIN) ) {                                /*新用户接入，分配资源，接受连接*/

                FDB_Accept connt(now_skfd);
                accepted_fd = connt.getAccepted_fd();
                user.User_add(connt);
                Epoll_add(accepted_fd, true, false);

                std::cout << "One New Client !" << std::endl;

            }else if (m_epEvent_p[ep_event_i].events & EPOLLOUT) {                      /*写事件*/

                //send()



            }else if (m_epEvent_p[ep_event_i].events & EPOLLIN) {                       /*读事件*/

/***********************************************测试代码********************************************/

                char tmp_buf[100];
                ssize_t recv_num = recv(now_skfd, tmp_buf, 100, 0);

                if(0 == recv_num) {                                                     /*客户端掉线*/

                    user.User_del(now_skfd);
                    Epoll_del(now_skfd);
                    std::cout << "Lost A Client ! " << std::endl;


                }

                std::cout << "Debug_message: Got a pice of message " << recv_num << " bites ";
                std::cout << "from fd: " << now_skfd << " client " << std::endl;
                send(now_skfd, tmp_buf, (size_t)recv_num, 0);


/************************************************测试代码****************************************************/

            }

        }/*end for(int i = 0; i < ret; i++)*/

    }/*end while(work_status)*/

}








FDB_Epoll::~FDB_Epoll() {

    delete[] m_epEvent_p;
}


