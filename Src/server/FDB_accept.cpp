/*************************************************************************
	> File Name: FDB_accept.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月18日 星期一 12时22分56秒
 ************************************************************************/

#include<iostream>
#include"./FDB_accept.h"
#include"./FDB_buffer.h"


Accept::Accept(int sockfd){
    
    sock_fd = sockfd;

    connfd = accept(sockfd,(struct sockaddr *)&client_addr,&client_addr_length);
    
    if(connfd == -1){

        std::cout << "accept error " << std::endl;

        
    }


}



int Accept::Accept_return(){
    
    return connfd;

}


int Accept::Accept_Write(char *str){        /*先写进connfd  将剩余的数据写入buffer ,注册connfd 可写*/
    char buf[1024];
    memcopy(buf,str,1024);
    int slave = write(connfd,buf,1024);
    if(slave > 0){  
        connfd_buf.connfd_write(str);
    }



}



int Accept::Accept_Read(char * str){
    char buf[1024];
    memcopy(buf,str,1024);
    int slave = read(connfd,buf,1024);
    if(slave > 0){  
        connfd_buf.connfd_read(str);
    }


}


