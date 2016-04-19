/*************************************************************************
	> File Name: FDB_socket_epoll_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月18日 星期一 15时41分44秒
 ************************************************************************/

#include<iostream>
#include"./FDB_Socket.cpp"
#include"./FDB_Socket.h"


#include"./FDB_accept.h"
#include"./FDB_accept.cpp"

#include"./FDB_epoll.cpp"
#include"./FDB_epoll.h"
int main(){

    Socket a(AF_INET,10);
    std::cout << a.fd()<< std::endl;
    int fd = a.fd();
    Epoll epo(fd);
    epo.Epoll_wait();


}

