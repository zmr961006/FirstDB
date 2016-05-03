/*************************************************************************
	> File Name: cilent.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月25日 星期一 18时13分55秒
 ************************************************************************/

#include<iostream>
#include<sys/socket.h>
#include<sys/time.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<stdio.h>


using namespace std;

int str_cil(int sockfd){
    
    char sendline[1024],recvline[1024];
    bzero(sendline,1024);
    for(;;){
        scanf("%s",sendline);
        write(sockfd,sendline,1024);
        while(read(sockfd,recvline,1024) > 0){  
            std::cout << recvline << std::endl;
            bzero(recvline,1024);
        }
        bzero(sendline,1024);
        bzero(recvline,1024);
    }


}



int main(int argc ,char **argv){

    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET,SOCK_STREAM,0);
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(9201);
    inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
    connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
    str_cil(sockfd);
    exit(0);

}


