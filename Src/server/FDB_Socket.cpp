/*************************************************************************
	> File Name: FDB_Socket.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月14日 星期四 08时30分26秒
 ************************************************************************/

#include<iostream>
#include<error.h>
#include<fcntl.h>
#include<stdio.h>
#include<strings.h>
#include<sys/socket.h>
#include<unistd.h>
#include"./FDB_Socket.h"


typedef struct sockaddr SA;



Socket::~Socket(){

    ::close(sockfd_);

}

Socket::Socket(sa_family_t family,int listen_num){
    
    backlog = listen_num;
    sockfd_ = socket(family,SOCK_STREAM,0);
    if(sockfd_ < 0){
        std::cout << "log_net_error" << std::endl;
    }

}

int Socket::setnonblocking(){
    
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;

}


bool Socket::bindAddress(const struct sockaddr & myaddr){
    
    int len = sizeof(myaddr);
    int ret = ::bind(sockfd_,myaddr,len);
    if(ret < 0){
        std::cout << "bind error" << std::endl;
        return false;
    }    
    return true;
}


bool Socket::listen(int backlog){
    
    int ret ;
    ret = ::listen(sockfd_,backlog);
    if(ret < 0){
        std::cout << "listen error" << std::endl;
        return false;
    }
    return true;

}


bool Socket::setReuseAddr(bool on){
    
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_REUSEADDR,&optval,static_cast<socklen_t>(sizeof optval));

    return true;

}



bool Socket::setReusePort(bool on){

    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_REUSEPORT,&optval,static_cast<socklen_t>(sizeof optval));

    return true;

}




bool Socket::setKeepAlive(bool on){
    
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_KEEPALIVE,&optval,static_cast<socklen_t>(sizeof optval));
    return true;
    

}



