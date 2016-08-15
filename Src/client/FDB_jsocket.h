/*************************************************************************
	> File Name: FDB_jsocket.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 08时24分15秒
 ************************************************************************/

#ifndef _FDB_JSOCKET_H
#define _FDB_JSOCKET_H

#define LISTENQ 15

#include"FDB_jheader.h"

class jSocket
{
public:
    jSocket();

    void Socket_bind();
    void Listen();
    void Accept();

    void my_err(const char* s, int a);


private:
    struct sockaddr_in servaddr;    
    int listenfd;                  /**/
    int connfd;                    /*已连接套接字*/

};


#endif
