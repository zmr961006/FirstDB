/*************************************************************************
	> File Name: FDB_jcli.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 14时25分06秒
 ************************************************************************/

#ifndef _FDB_JCLI_H
#define _FDB_JCLI_H

#include"FDB_jheader.h"
#include"FDB_json.h"
#include"FDB_judge_commd.h"

class jcli
{

public:

    jcli();
    jcli(char* s);   /*构造函数*/
    void Socket();   /*创建套接字*/
    void Connect();  /*建立连接*/
    int input_commd_name(std::string buff[MAXLINE]);              /*输入函数*/

    void print_prompt();        /*客户端提示符输出*/

    void my_err(const char* s, int line);


private:
    struct sockaddr_in servaddr;
    int socketfd;
    char sip[64];                            /*保存命令行传入的服务器IP地址*/
    std::string sendline;

};

#endif
