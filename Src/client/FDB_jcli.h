/*************************************************************************
	> File Name: FDB_jcli.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 14时25分06秒
 ************************************************************************/

#ifndef _FDB_JCLI_H
#define _FDB_JCLI_H

#define PORT 4055                 /*服务器端口号*/
#define MAXLINE 4096
#include"FDB_jheader.h"


class jcli
{

public:
    jcli();
    jcli(char* s);
    void Socket();
    void Connect();

    int c_tojson();

    void my_err(const char* s, int line);
    void str_cli();


private:
    struct sockaddr_in servaddr;
    int socketfd;
    char sip[64];                            /*保存命令行传入的服务器IP地址*/
    char sendline[MAXLINE];                      /*一次性能传送的数据大小为4096个字节*/

};

#endif
