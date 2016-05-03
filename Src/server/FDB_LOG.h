/*************************************************************************
	> File Name: FDB_LOG.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月13日 星期三 17时02分41秒
 ************************************************************************/

#ifndef _FDB_LOG_H
#define _FDB_LOG_H

#include<iostream>
#include<mutex>
#include<thread>
#include<cstdlib>
#include<string>
#include<cstring>
#include<unistd.h>
#include<vector>
#include<fstream>

#define LOG_BUFFER_MAX  (1 << 12)   //缓冲区大小
#define LOG_BUFFER_SIZE 5           //缓冲区个数
#define LOG_SIZE 1 << 8             //日志字节大小

class LOG_fd
{
private:
    int fd;
public:
    std::mutex mutex_fd;
    LOG_fd() = default;
};

class LOG_Buffer
{
private:
    char (*buffer)[LOG_SIZE];
    int used;
    LOG_fd log_fd;
public:
    std::mutex mutex_buffer;
    LOG_Buffer();
    ~LOG_Buffer();
    bool Buffer_Add(const char *str, int size);    //添加一条信息
    bool Buffer_Write();  //调用LOG_fd中的write
};

class FDB_LOG
{
private:
    LOG_Buffer aof_buffer[LOG_BUFFER_SIZE];
public:
    FDB_LOG() = default;
    ~FDB_LOG() = default;
    bool FDB_LOG_ADD(const char * a);
    bool FDB_LOG_Write();
    std::vector<std::string> FDB_LOG_Read();  //读文件不用加锁，处于初始化作用
};


#endif
