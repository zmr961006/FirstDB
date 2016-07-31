//
// Created by butter on 16-7-28.
//

#ifndef MY_NETLIB_FDB_SERVER_H
#define MY_NETLIB_FDB_SERVER_H


#include <iostream>
#include "FDB_Epoll.h"
#include "FDB_Socket.h"
#include <thread>

class FDB_Server {

public:

    FDB_Server(int status, int connfd_num, int pthread_num);
   ~FDB_Server();


    bool server_start();
    int  get_server_fd();

/*
    bool server_end();
    bool server_change(int status);
    int  server_get_status();
*/

private:

    int m_iServer_status;
    int m_iConnfd_num;
    int m_iChanges;
    int m_iSocketfd;
    int m_iServer_thread_num;
};

static void server_work(int fd);
#endif //MY_NETLIB_FDB_SERVER_H
