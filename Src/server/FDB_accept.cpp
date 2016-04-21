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
