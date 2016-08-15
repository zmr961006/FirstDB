/*************************************************************************
	> File Name: FDB_epoll.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 20时43分13秒
 ************************************************************************/

#include<iostream>
#include"./FDB_epoll.h"
#include"./FDB_accept.h"
#include<thread>
#include"./FDB_json.h"
using namespace std;
extern User user;

Epoll::Epoll(int fd){                /*EPoll构造函数*/

    epoll_fd = epoll_create1(0);
    Epoll_create_events();
    if(epoll_fd == -1){
        std::cout << "error" << std::endl;
    }
    //std::cout << epoll_fd << std::endl;
    sock_fd = fd ;

}


bool Epoll::Epoll_setnonblock(int fd){          /*设置非阻塞*/
    
    int old_option = fcntl(fd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;

} 

int Epoll::Epoll_return_fd(){

    return epoll_fd;

}




bool Epoll::Epoll_reset(int fd){                /*重新设置LIN LET SHOT */ 

    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLET | EPOLLONESHOT;
    epoll_ctl(epoll_fd,EPOLL_CTL_MOD,fd,&event);
    
}

bool Epoll::Epoll_set_EPOLLOUT(int fd){
    
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLOUT | EPOLLET | EPOLLONESHOT;
    epoll_ctl(epoll_fd,EPOLL_CTL_MOD,fd,&event);

}



bool Epoll::Epoll_del(int fd){                  /*删除套接字*/

    epoll_event event;
    event.data.fd = fd;
    epoll_ctl(epoll_fd,EPOLL_CTL_DEL,fd,&event);

}

bool Epoll::Epoll_add_listen(int fd , bool enable_et){     /*添加监听套接字*/

    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN;
    if(enable_et){
        event.events |= EPOLLET;
    }
      
    epoll_ctl(epoll_fd,EPOLL_CTL_ADD,fd,&event);
    return true;
}






bool Epoll::Epoll_add(int fd,bool enable_et,bool oneshot){     /*添加fd 到Epoll*/
    
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


bool Epoll::Epoll_create_events(){                    /*建立Epoll 文件描述符集合*/

    event_s = new epoll_event[MAX_NUM];
    if(!event_s){

        std::cout << "create events error !! go to log now " << std::endl;
        return false;

    }
    return true;    

}


Epoll::~Epoll(){
    

    delete event_s;


}


bool Epoll::Epoll_wait(){                                 /*epoll 核心wait*/

    bool do_work = true;
    bool test;
    test = Epoll_add_listen(sock_fd,false);
    std::cout << test << std::endl;

    while(do_work){
        //std::cout << "AAA" << std::endl;
        int ret = epoll_wait(epoll_fd,event_s,MAX_NUM,-1);
        std::cout << "sssss" << std::endl;
        if(ret < 0){
            
            std::cout << "epoll failure " << std::endl;
            break;

        }

        for(int i = 0;i < ret;i++){
            int sockfd = event_s[i].data.fd;
            int connfd;
            if( (event_s[i].events & EPOLLERR)  ||
                (event_s[i].events & EPOLLHUP)  ||
                (!(event_s[i].events & EPOLLIN))){
                
                std::cout << "error epoll " << std::endl;
                close(event_s[i].data.fd);
                continue;

            }else if(sockfd == sock_fd){
                
                Accept connt(sockfd);
            
                connfd = connt.Accept_return();
                user.User_add(connt);   
                Epoll_setnonblock(connfd); /********/
                Epoll_add(connfd,true,false);

            }else if(event_s[i].events & EPOLLIN){
            
                /*测试读取信,此处应当包含一个md5解密和一个JSon解析模块*/
                /*第一阶段设计，在EPOLLIN 这里直接处理请求并回复*/
                /*第二阶段设计，添加备机，组装节点*/
                /*第三阶段设计，组织分布式存储结构*/
                char buf[1024];
                //std::cout <<"ths id : " <<std::this_thread::get_id() << std::endl;
                /*
                Epoll_set_EPOLLOUT(connfd);
                */
                //std::cout << "id = events " << event_s[i].data.fd << " " << std::endl;
                read(event_s[i].data.fd,buf,1024);
                fdb_json A;
                A.json_tostr(buf);
                string store;
                store = db.handle(A.get_comm_name(),A.get_key(),A.get_value(),A.get_jadd());
                memset(buf,0,1024);
                memcpy(buf,store.c_str(),1024);
                write(event_s[i].data.fd,buf,1024);
                //bzero(buf,1024);
                //std::string bu(700000,'c');
                //int flag;
                //std::cout << bu << std::endl;
                //flag = user.User_return(connfd).Accept_Write(bu);
                //std::cout << flag << std::endl;
                /*if(user.User_return(connfd).Accept_return_flag()){
                    
                    std::cout << "PPPPPP" << std::endl;
                    Epoll_set_EPOLLOUT(connfd);
                    
                }else{*/  
                    
                    Epoll_reset(event_s[i].data.fd);

                //}   

            }else if(event_s[i].events & EPOLLOUT){
                
            
                
            }else{
                
                //anything else
            }
        }

    
    
    }
    close(sock_fd);
    close(epoll_fd);


}




bool Epoll::Epoll_getMAX_NUM(){                     /*epoll 最大监听套接字个数*/
    
    MAX_NUM = 100;
    return true;

}



/*void Epoll::Epoll_do(){
    
    Epoll epo(sock_fd);
    epo.Epoll_wait();
    

}*/


bool Epoll::work(int sockfd,std::string string,char *buf){
    



}





