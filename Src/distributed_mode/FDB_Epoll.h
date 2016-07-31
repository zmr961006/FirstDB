//
// Created by butter on 16-7-26.
//

#ifndef MY_NETLIB_EPOLL_H
#define MY_NETLIB_EPOLL_H


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/epoll.h>
#include<pthread.h>
#include <assert.h>

class FDB_Epoll {

public:

    FDB_Epoll(int fd);                                                  /*构造函数*/
   ~FDB_Epoll()      ;                                                  /*析构函数*/

    bool Epoll_create_events();                                         /*创建epoll_event*/
    bool Epoll_reset(int fd);                                           /*重置epoll_fd*/
    bool Epoll_add(int fd, bool enable_et, bool oneshot);               /*添加可读事件*/
    bool Epoll_add_initListen(int fd, bool enable_et);                      /*添加监听事件*/
    bool Epoll_setnoblocking(int socket_fd);                            /*设置非阻塞*/
    bool Epoll_del(int fd);                                             /*删除epoll事件*/
    bool Epoll_wait();                                                  /*核心函数*/

private:

    int m_iEpoll_fd             ;
    const int m_ciMAX_NUM = 100 ;
    int m_iBUF_SIZE             ;
    int m_iListen_fd            ;
    epoll_event * m_epEvent_p   ;

};


#endif //MY_NETLIB_EPOLL_H
