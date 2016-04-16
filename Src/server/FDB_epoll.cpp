/*************************************************************************
	> File Name: FDB_epoll.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 20时43分13秒
 ************************************************************************/

#include<iostream>
#include"./FDB_epoll.h"

using namespace std;


Epoll::Epoll(){

    epoll_fd = epoll_create1(0);
    if(epoll_fd == -1){
        std::cout << "error" << std::endl;
    }

}


bool Epoll::Epoll_setnonblock(int fd){
    
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;

} 

bool Epoll::Epoll_reset(int fd){

    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
    epoll_ctl(epoll_fd,EPOLL_CTL_MOD,fd,&event);
    
}


bool Epoll::Epoll_add(int fd,bool enable_et,bool oneshot){
    
    epoll_event event;
    event.data.fd = fd;
    event.events  = EPOLLIN;
    if(enable_et){
        event.events  |= EPOLLET;

    }
    if(oneshot){
        event.events  |= EPOLLONESHOT;

    }

    epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd,&event);
    Epoll_setnonblock(fd);    
        
    return true;
}


bool Epoll::Epoll_wait(){

    bool do_work = true;

    while(do_work){
        
        int ret = epoll_wait(epoll_fd,events,MAX_NUM-1);

        if(ret < 0){
            
            std::cout << "heart data " << std::endl;

        }

        work(events,ret,epoll_fd,fd);

    }
    


}



