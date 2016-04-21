/*************************************************************************
	> File Name: FDB_server.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 10时05分23秒
 ************************************************************************/

#ifndef _FDB_SERVER_H
#define _FDB_SERVER_H

/*服务器启动实例*/

#include"./FDB_Socket.h"
#include"./FDB_accept.h"
#include"./FDB_buffer.h"
#include"./FDB_epoll.h"
#include<thread>


class server{

    public:
            
        server(int status,int connfd_num,int server_s);
        bool server_start();
        bool server_end();
        bool server_change(int status);
        int server_get_status();
        int server_fd();
        //static void server_work();
    
    private:

        int server_status;
        int connfd_num   ;
        int change       ;
        int sockfd       ;
        int server_threads;

};

static void server_work(int fd);



#endif
