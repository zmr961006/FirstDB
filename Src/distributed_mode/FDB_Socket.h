//
// Created by butter on 16-7-26.
//

#ifndef MY_NETLIB_SCOKET_H
#define MY_NETLIB_SCOKET_H

#include <iostream>
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

struct tcp_info;  /*????????????????????????????*/

class FDB_Socket {

public:

    explicit FDB_Socket(int sockfd):m_iSockfd(sockfd){};                       /*声明为explicit的构造函数不能在隐式转换中使用。,如果存在直接赋值*/

    FDB_Socket(sa_family_t family, int listen_num);
    ~FDB_Socket();

    bool Socket_createSocket(sa_family_t family = AF_INET, int backlog = 100);             /*构造核心函数*/
    bool Socket_bindAddress();                                                  /*命名套接字*/
    bool Socket_listen(int backlog);                                            /*监听套接字*/
    bool Socket_setReusePort(bool on);                                          /*设置端口重用*/
    bool Socket_setTimeOutRecnt(bool on);                                       /*设置超时重连*/
    int  Socket_setNoBlocking();                                                /*设置 m_iSockfd 为非阻塞*/
    int  Socket_getfd();                                                        /*获取套接字描述符 m_iSockfd*/

    int  Socket_do_accept();
    bool Socket_getbacklog();
    bool Socket_shutdownWrite();
    bool Socket_TcpNoDelay(bool on);
    bool Socket_setResuseAddr(bool on);
    bool Socket_setKeepAlive(bool on);
    bool test_accept();
/*
    bool Socket_getTcpInfo(struct tcp_info *) const;
    bool Socket_getTcpInfoString(char * buf, int len) const;
*/
private:

    int m_iSockfd;
    int m_iBacklog;
    struct sockaddr_in m_addr_inAddress;
    struct sockaddr_in m_addr_inCliaddr;

};


#endif //MY_NETLIB_SCOKET_H
