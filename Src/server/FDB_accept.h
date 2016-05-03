/*************************************************************************
	> File Name: FDB_accept.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月18日 星期一 12时22分50秒
 ************************************************************************/

#ifndef _FDB_ACCEPT_H
#define _FDB_ACCEPT_H

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<cstring>
#include<unistd.h>
#include"./FDB_buffer.h"
#include"./FDB_epoll.h"

class Epoll;

class Accept{
    
    public:
        Accept()= default;
        Accept(int sockfd);
        ~Accept()= default;
        int Accept_return();
        int Accept_Write(std::string str);
        int Accept_Read(char * str);
        int Accept_return_flag();
        int Accept_send_buffer();    

    private:
        int connfd;
        int sock_fd;
        int id     ;
        int connfd_flag;
        struct sockaddr_in client_addr;
        socklen_t client_addr_length = sizeof(client_addr);  
        Buffer connfd_buf;
            

};



#endif
