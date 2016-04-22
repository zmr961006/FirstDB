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
#include<thread>

static int fd ;
void func(){
    std::cout << "AAAAAAAAAAAAAA" << std::endl;
    Epoll epo(fd);
    epo.Epoll_wait();
}

void funb(){

    std::cout << "GGGGGGGGGGGGG" << std::endl;
    Epoll epo(fd);
    epo.Epoll_wait();


}



//static int fd ;

int main(){

    Socket a(AF_INET,10);
    std::cout << a.fd()<< std::endl;
    fd = a.fd();
    /*Epoll epo(fd);
    epo.Epoll_wait();*/
    thread t1(func);
    thread t2(funb);   
    //thread t2(func);
    //thread t3(func);
    t1.join();
    t2.join();
    //t3.join();
}

