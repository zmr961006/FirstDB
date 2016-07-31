/*************************************************************************
	> File Name: FDB_jclient.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 08时32分36秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include"FDB_jcli.h"

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
    
    strncpy(sip, s, strlen(s));                 /*初始化要连接的服务器IP*/

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

    if( inet_pton(AF_INET, sip, &servaddr.sin_addr)  <= 0){
        my_err("client inet_pton error ", __LINE__);
    }

    if( connect(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 ){
        my_err("client connect error ", __LINE__);
    }

    Json::Reader reader;
    Json::Value root;

    if( (the_pid = fork()) == 0){
        for(; ;)
        {
            jcli::str_cli();

            if(reader.parse(sendline, root) == 0){
                my_err("client string to json error ", __LINE__);
            }

            if( write(socketfd, sendline, strlen(sendline)) != strlen(sendline) ){
                my_err("client write error ", __LINE__);
            }

            bzero(sendline, sizeof(sendline) );
        }
    }
    else
    {
        /*阻塞等待服务器发来已断开信息*/
        while(read(socketfd, buff, MAXLINE));
        my_err("服务器过早退出 ", __LINE__);
        
    }

}

/*将普通字符串转换成json格式的字符串*/
void jcli::str_cli()
{
    
    char buff[MAXLINE];                         /*临时存放输入*/


    char  str ='{';
    const char * str1 = "\"";
    const char * str2 = ":";
    const char * str3 = ",";
    const char * str4 = "}";

    const char * name = "name";
    const char * fast = "fast";
    const char * last = "last";

    sendline[0] = str;
        
    bzero(buff, sizeof(buff) );
    //std::cin >> buff;

    scanf("%s",buff);


    strncat(sendline, str1, strlen(str1));
    strncat(sendline, name, strlen(name));
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, str2, strlen(str2));

    strncat(sendline, str1, strlen(str1));
    strncat(sendline, buff,strlen(buff));
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, str3, strlen(str3));
    
    bzero(buff, sizeof(buff) );
    //std::cin >> buff;
    
    scanf("%s",buff);
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, fast, strlen(fast));
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, str2, strlen(str2));

    strncat(sendline, str1, strlen(str1));
    strncat(sendline, buff,strlen(buff));
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, str3, strlen(str3));

    bzero(buff, sizeof(buff) );

    //std::cin >> buff;
    scanf("%s",buff);

    strncat(sendline, str1, strlen(str1));
    strncat(sendline, last,strlen(last));
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, str2, strlen(str2));

    strncat(sendline, str1, strlen(str1));
    strncat(sendline, buff,strlen(buff));
    strncat(sendline, str1, strlen(str1));
    strncat(sendline, str4, strlen(str4));

}

int main(int argc,char *argv[])
{
    jcli a(argv[1]);


    //a.str_cli();
    
    a.Socket();
    a.Connect();

    return 0;
}
