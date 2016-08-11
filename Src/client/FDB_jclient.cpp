/*************************************************************************
	> File Name: FDB_jclient.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 08时32分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include"FDB_jcli.h"
#include"FDB_json.h"

jcli::jcli()
{
    socketfd = -1;
    sip[0]='\0';

}

jcli::jcli(char* s)
{
    bzero(&servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    socketfd = -1;
    strcpy(sip, s);
    //strncpy(sip, s, strlen(s));                 /*初始化要连接的服务器IP*/
}

void jcli::Socket()
{
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketfd < 0){
        my_err("client socket creat error ", __LINE__);
    }
}


void jcli::my_err(const char* s, int line)
{
    std::cout <<"line " << line << ":  " << s << std::endl;
    exit(-1);
}

/*连接并发送数据*/
void jcli::Connect()
{
    pid_t  the_pid;
    char buff[MAXLINE];                 /*在父进程检查服务器是否断开*/
    char buff_1[MAXLINE];                 /*在父进程检查服务器是否断开*/

    int m;

    if( ( m = inet_pton(AF_INET, sip, &servaddr.sin_addr) )  <= 0){
        printf("%d\n", m);
        my_err("client inet_pton error ", __LINE__);
    }

    if( connect(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 ){
        my_err("client connect error ", __LINE__);
    }

    if( (the_pid = fork()) == 0){
        
        for(; ;){
            
            fdb_json A;                       /*定义对象A获取fdb_json类的成员*/
            sendline = A.input_str_tojson();

            if( write(socketfd, sendline.c_str(), sendline.size() ) != sendline.size()){
                my_err("client write error ", __LINE__);
            }

            sendline = "\0";
        }
    }
    else
    {
        //阻塞等待服务器发来已断开信息
        while(read(socketfd, buff, MAXLINE)){
            printf("hh_%s\n", buff);
            bzero(buff, sizeof(buff) );
        }
        my_err("服务器过早退出 ", __LINE__);
        
    }
}

int main(int argc,char *argv[])
{
    if(argc < 2){
        std::cout << __LINE__ << ": 参数格式不对,正确格式为：可执行文件名+IP地址" << std::endl;
        exit(-1);
    }
    jcli a(argv[1]);

    a.Socket();
    a.Connect();

    return 0;
}
