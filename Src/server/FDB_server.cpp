/*************************************************************************
	> File Name: FDB_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 13时38分57秒
 ************************************************************************/

#include<iostream>
#include"./FDB_server.h"
#include<thread>

server::server(int status ,int connfd_num,int server_s){
    
    server_status = status;
    connfd_num = connfd_num;
    server_threads = server_s;
    
}


bool server::server_start(){
    
    Socket db_server(AF_INET,10);

    sockfd = db_server.fd();

    std::thread threads[server_threads];
    std::cout << server_threads << "ssss" << std::endl; 
    for(int i = 0;i < server_threads;i++){
        
        threads[i] = std::thread(server_work,sockfd);    

    }

    for(int i = 0;i < server_threads;i++){
        
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


