/*************************************************************************
	> File Name: FDB_Socket.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月14日 星期四 08时14分50秒
 ************************************************************************/

#ifndef _FDB_SOCKET_H
#define _FDB_SOCKET_H


/*这里封装了基本的socket*/ 

#include<iostream>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<strings.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#include"./FDB_accept.h"



struct tcp_info;

class Socket{

    public:
        explicit Socket(int sockfd):sockfd_(sockfd){}   /*如果存在直接赋值*/
    
        bool Socket__(sa_family_t family = AF_INET,int backlog = 100);   /*构造核心函数*/
        ~Socket();
        int fd()const{return sockfd_; }
        Socket(sa_family_t family,int listen_num);  /*构造函数*/
        bool getTcpInfo(struct tcp_info *)const;
        bool getTcpInfoString(char *buf,int len)const;
    
        bool bindAddress();                         /*绑定IP/PORT 信息*/
        bool listen(int backlog);                   /*监听套接字*/

        int  do_accept();                           /*一个简单测试回射*/
        bool getbacklog();                          /*返回监听数目*/
        bool shutdownWrite();                     
        bool setTcpNoDelay(bool on);
        bool setReuseAddr(bool on);                        /*设置重用地址*/
        bool setReusePort(bool on);                        /*设置重用端口*/
        int  setnonblocking();                             /*设置非阻塞套接字*/
        bool setbuffsize(bool on);      
        bool setKeepAlive(bool on);                        /*设置保活机制*/
        bool test_accept();

    private:
        int sockfd_ ;
        int backlog;
        struct sockaddr_in address;      
        struct sockaddr_in cliaddr;



};






#endif
