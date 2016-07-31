//
// Created by butter on 16-7-26.
//

#ifndef MY_NETLIB_ACCEPT_H
#define MY_NETLIB_ACCEPT_H


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


class FDB_Accept {

public:

    FDB_Accept() = default;
    FDB_Accept(int request_fd);
    ~FDB_Accept();
    int getAccepted_fd();
/*  int Accept_write(char * str);
    int Accept_read (char * str);
*/
private:

    int m_iAccepted_fd;
    struct sockaddr_in m_Client_addr;
    socklen_t m_cli_AddrLength = sizeof(m_Client_addr);

    /*int m_iSock_fd;*/
    /*char connfd_buf[100];*/
    /*Buffer connfd_buf;*/
    /*int id;*/

};


#endif //MY_NETLIB_ACCEPT_H
