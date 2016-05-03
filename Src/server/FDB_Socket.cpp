/*************************************************************************
	> File Name: FDB_Socket.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月14日 星期四 08时30分26秒
 ************************************************************************/

/*#include<iostream>
#include<error.h>
#include<fcntl.h>
#include<stdio.h>
#include<strings.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include"./FDB_Socket.h"
*/

#include"./FDB_Socket.h"
typedef struct sockaddr SA;



Socket::~Socket(){                      

    ::close(sockfd_);

}

bool Socket::Socket__(sa_family_t family,int listen_num){    /*创建一个Socket*/
    
    backlog = listen_num;
    sockfd_ = socket(family,SOCK_STREAM,0);
    if(sockfd_ < 0){
        std::cout << "log_net_error" << std::endl;
    }

}

int Socket::setnonblocking(){              /*设置非阻塞*/
    
    int old_option = fcntl(sockfd_,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(sockfd_,F_SETFL,new_option);
    return old_option;

}


bool Socket::bindAddress(){                /*绑定IP 端口*/
    
    //int len = sizeof(*myaddr);
    std::cout << "sockfd = " << sockfd_ << " len = " << sizeof(address) << std::endl;
    int ret = bind(sockfd_,(struct sockaddr *)&address,sizeof(address));
    std::cout << ret << std::endl;
    if(ret < 0){
        std::cout << ret << std::endl;
        std::cout << "bind error" << std::endl;
        return false;
    }    
    return true;
}


bool Socket::listen(int backlog){       /*监听最大链接数*/
    
    int ret ;
    ret = ::listen(sockfd_,backlog);
    if(ret < 0){
        std::cout << "listen error" << std::endl;
        return false;
    }
    return true;

}


bool Socket::setReuseAddr(bool on){      /*设置reuseaddr 标志*/
    
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_REUSEADDR,&optval,static_cast<socklen_t>(sizeof optval));

    return true;

}

bool Socket::setbuffsize(bool on){
    
    int optval = on ? 1: 0;
    int size = 4096;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_SNDBUF,&size,sizeof(optval));


}


bool Socket::setReusePort(bool on){      /*设置reuseport*/

    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_REUSEPORT,&optval,static_cast<socklen_t>(sizeof optval));

    return true;

}




bool Socket::setKeepAlive(bool on){      /*设置保活*/
    
    int optval = on ? 1 : 0;
    ::setsockopt(sockfd_,SOL_SOCKET,SO_KEEPALIVE,&optval,static_cast<socklen_t>(sizeof optval));
    return true;
    

}


Socket::Socket(sa_family_t family,int listen_num){
    
    

    Socket__(family,listen_num);
    //setReuseAddr(true);
    setReusePort(true);
    setbuffsize(true);
    bzero(&address,sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port  = htons(9201);
    
    //Socket__(family,listen_num);
    if(bindAddress() && (sockfd_ > 0)){
        if(listen(listen_num)){
            if(setnonblocking()){
                return;    
            }
            
        }
    }


}

int Socket::do_accept(){
    
    socklen_t clen;
    int connfd;
    for(;;){
        clen = sizeof(cliaddr);
        if(connfd = accept(sockfd_,(SA*)(&cliaddr),&clen)){
            std::cout << "sksksks" << std::endl;
            if(fork() == 0){
                char buf[100];
                for(;;){   
                    while(read(connfd,buf,100) > 0){
                        std::cout << buf << std::endl;
                    }
                }   
            }
            
        }
    }
}


bool Socket::test_accept(){
    
    //Accept user(sockfd_);
    while(1){
        
        Accept user(sockfd_);
        if(user.Accept_return()){
            if(fork() == 0){
                char buf[100];
                for(;;){
                    while(read(user.Accept_return(),buf,100) > 0){
                        std::cout << buf << std::endl;
                    }
                }
            }
        }
    }



}


