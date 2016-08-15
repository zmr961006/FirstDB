/*************************************************************************
	> File Name: FDB_header.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年07月26日 星期二 14时27分26秒
 ************************************************************************/

#ifndef _FDB_HEADER_H
#define _FDB_HEADER_H

#define PORT 9201           /*自定义服务器端口号*/
#define MAXLINE 4096         /*一般字符数组的大小限定*/
#define MAXSTR 833          /*命令个数26*30+8，假设a-z中每一个字符开头的命令有30个，多加8个用来以防万一*/
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netdb.h>
#include<fcntl.h>
#include<netinet/in.h>
#include<json.h>
#include<json/json.h>

#endif

