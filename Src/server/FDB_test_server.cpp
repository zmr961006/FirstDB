/*************************************************************************
	> File Name: FDB_test_server.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 14时08分16秒
 ************************************************************************/

#include<iostream>
#include"./FDB_server.h"
#include"./FDB_epoll.h"
#include"./FDB_Socket.h"
#include<thread>
#include"./FDB_buffer.h"

int main(){

    server DB(1,100,2);
    DB.server_start();


}
