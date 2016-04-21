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



class server{

    public:
            
        server(int status,int connfd_num);
        bool server_start();
        bool server_end();
        bool server_change(int status);
        int server_get_status();

    private:

        int server_status;
        int connfd_num   ;
        int change       ;


};




#endif
