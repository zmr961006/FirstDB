//
// Created by butter on 16-7-28.
//

#include "FDB_Server.h"


FDB_Server::FDB_Server(int status, int connfd_num, int pthread_num) {   /*构造服务器基础信息*/

    m_iServer_status     = status;                                      /*服务器状态*/
    m_iConnfd_num        = connfd_num;                                  /*最大链接个数，其实需要限定下*/
    m_iServer_thread_num = pthread_num;                                 /*可配置的PEUSEPORT 个数*/

}


bool FDB_Server::server_start() {

    FDB_Socket    db_Server(AF_INET, 10)  ;
    m_iSocketfd = db_Server.Socket_getfd();

    std::thread   threads[m_iServer_thread_num];                          /*可配置的服务器线程数*/

    for(int i = 0 ; i < m_iServer_thread_num; i++) {

        threads[i] = std::thread(server_work, m_iSocketfd);

    }

    for(int i = 0; i < m_iServer_thread_num; i++) {

        threads[i].join();
    }

}

static void server_work(int fd ) {

    FDB_Epoll epo(fd);
    epo.Epoll_wait() ;

}
int  FDB_Server::get_server_fd() {

    return  m_iSocketfd;
}

/*
bool FDB_Server::server_end();
bool FDB_Server::server_change(int status);
int  FDB_Server::server_get_status();
*/

FDB_Server::~FDB_Server(){

}