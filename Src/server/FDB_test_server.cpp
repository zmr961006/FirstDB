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
#include"../jsoncpp-src-0.5.0/include/json/json.h"

#include<stdlib.h>
#include<string.h>

/*说明，这个测试文件关乎全局，暂时不能添加进/test/ */



/*服务器测试****************/

User user;


int main(){

    server DB(1,100,2);
    DB.server_start();
    

}


