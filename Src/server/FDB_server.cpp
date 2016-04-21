/*************************************************************************
	> File Name: FDB_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 13时38分57秒
 ************************************************************************/

#include<iostream>
#include"./FDB_server.h"
#include<thread>

server::server(int status ,int connfd_num,int server_s){   /*构造服务器基础信息*/

    server_status = status;                                /*服务器状态*/
    connfd_num = connfd_num;                               /*最大链接个数，其实需要限定下*/
    server_threads = server_s;                             /*可配置的PEUSEPORT 个数*/
    
}


bool server::server_start(){                               /*开启多线程服务器*/
    
    Socket db_server(AF_INET,10);                          /*建立服务器的实例*/ 

    sockfd = db_server.fd();                               /*服务器的链接字*/

    std::thread threads[server_threads];                   /*可配置的服务器线程数*/
    //std::cout << server_threads << "ssss" << std::endl; 
    for(int i = 0;i < server_threads;i++){
        
        threads[i] = std::thread(server_work,sockfd);      /*开启配置的epoll */

    }

    for(int i = 0;i < server_threads;i++){                 /*等待线程结束*/
        
        threads[i].join();
    }

}

static void server_work(int fd){
    
    Epoll epo(fd);
    epo.Epoll_wait();


}

int server::server_fd(){
    
    return sockfd;

}


