/*************************************************************************
	> File Name: FDB_epoll.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月16日 星期六 20时43分26秒
 ************************************************************************/

#ifndef _FDB_EPOLL_H
#define _FDB_EPOLL_H


#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<unistd.h>
#include<string>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<time.h>



class Epoll{
    

    public:

        Epoll();
        ~Epoll(){}
        bool Epoll_create();
        bool Epoll_add(int fd,bool enable_et,bool oneshot);
        bool Epoll_reset(int fd);
        bool Epoll_del();
        bool Epoll_up();
        bool Epoll_wait();
        bool Epoll_setnonblock(int fd);
        bool Epoll_setMAX_NUM();
        
        void (*work)(int);
        void (*timer)(int);

    private:

        int epoll_fd;
        int MAX_NUM = 100; /*假定有100，应当从配置文件中读取*/
        int buf_SIZE;
        struct epoll_event events[MAX_NUM];
        
        
};





#endif
