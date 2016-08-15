/*************************************************************************
	> File Name: FDB_jclient.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 08时32分36秒
 ************************************************************************/

#include"FDB_jcli.h"

jcli::jcli(char* s)
{
    bzero(&servaddr, sizeof(servaddr) );
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    socketfd = -1;
    strcpy(sip, s);
    //strncpy(sip, s, strlen(s));                 /*初始化要连接的服务器IP*/
}

/*创建客户端套接字*/
void jcli::Socket()
{
    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    if(socketfd < 0){
        my_err("client socket creat error ", __LINE__);
    }
}
/*自定义检错函数*/
void jcli::my_err(const char* s, int line)
{
    std::cout <<"line " << line << ":  " << s << std::endl;
    exit(-1);
}

/*输入命令函数*/
int jcli::input_commd_name(std::string buff[MAXLINE])
{
    print_prompt();
    int i = 0;
    std::cin >> buff[i];              /*接收输入的字符串组*/
    sendline = sendline + buff[i];    /*将输入的字符串存入发送缓冲区中*/
    std::string result;               /*返回命令判断的结果*/
    std::string ok = "ok";            /*和命令判断结果做比较*/

    while( i < 5 ){
        i++;
        if(getchar() == '\n'){
            break;
         }
        std::cin >> buff[i];
        sendline = sendline + buff[i];
    }
    
    judge_commd A;          /*定义对象调用成员函数判断命令是否合法*/
    if( strcmp( (char *) (result = A.judge_commd_func( (char *)buff[0].c_str(), i) ).c_str(), (char* )ok.c_str() )  != 0 ){
        std::cout << result << std::endl;
        sendline = "\0";
        return -1;
    }
    
    if( i != 2 ){
        std::cout << result << std::endl;
    }
    return i;
}

/*客户端提示符*/
void jcli::print_prompt()
{
    std::cout << sip << ":" << PORT << "> ";
}


/*连接并发送数据*/
void jcli::Connect()
{
    pid_t  the_pid;
    char buff[MAXLINE];                 /*在父进程检查服务器是否断开*/
    char buff_1[MAXLINE];                 /*在父进程检查服务器是否断开*/

    std::string pre_commd[MAXLINE];      /*临时存储输入命令*/
    int m;

    if( ( m = inet_pton(AF_INET, sip, &servaddr.sin_addr) )  <= 0){
        printf("%d\n", m);
        my_err("client inet_pton error ", __LINE__);
    }

    if( connect(socketfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0 ){
        my_err("client connect error ", __LINE__);
    }

    if( (the_pid = fork()) == 0){
        
        fdb_json A;                       /*定义对象A获取fdb_json类的成员*/
        int count;                         /*定义一个整型变量代表输入的参数个数*/

        for(; ;){
            
            count = input_commd_name(pre_commd);            /*输入命令并判断命令是否正确*/
            
            /*如果如入命令不符，不往下继续执行*/
            if(count <= 0){
                continue;
            }
        
            sendline = A.str_tojson(count, pre_commd);     /*将命令字符串转换为json格式*/

            /*将json格式的字符串发给服务器*/
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
            printf("%s\n", buff);
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
