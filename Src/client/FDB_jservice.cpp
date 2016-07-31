/*************************************************************************
	> File Name: FDB_jservice.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 09时49分11秒
 ************************************************************************/

#include<iostream>
#include"FDB_jsocket.h"


using namespace std;

/*构造函数初始化*/
jSocket::jSocket()
{

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    listenfd = -1;
    connfd = -1;
}

/*套接字创建然后转为监听套接字*/
void jSocket::Socket_bind()
{
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1){
        my_err("service socket create error", __LINE__);
    }

    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr) ) == -1){
        my_err("service socket bind error ",  __LINE__);
    }
}

/*错误处理函数*/
void jSocket::Listen()
{
    if(listen(listenfd, LISTENQ) == -1){
        my_err("service socket Listen error ", __LINE__);
    }
}

void jSocket::my_err(const char* s, int line)
{
    std::cout <<"line " << line << ":  " << s << std::endl;
    exit(-1);
}

void jSocket::Accept()
{
    int n;
    char buff[MAXLINE];
    Json::Reader reader;
    Json::Value root;
    Json::StyledWriter sty;

    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);
    for(; ;){
        
        if(connfd < 0)
            my_err("socket accept error ", __LINE__);
        if((n = read(connfd,buff, MAXLINE)) == 0){
            close(connfd);
        }

        if(reader.parse(buff, root) == 0){
            my_err("service string to json erro ", __LINE__);
        }

        std::cout << root["name"].asString() << " ";
        std::cout << root["fast"].asString() << " ";
        std::cout << root["last"].asString() << std::endl;

        //std::cout << sty.write(root) << std::endl;
       bzero(buff, sizeof(buff));


    }

}


int main(int argc, char* argv[])
{
    jSocket a;

    a.Socket_bind();
    a.Listen();
    a.Accept();


    return 0;
}








