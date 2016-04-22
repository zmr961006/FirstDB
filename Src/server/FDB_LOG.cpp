/*************************************************************************
	> File Name: FDB_LOG.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月13日 星期三 17时05分45秒
 ************************************************************************/

#include<iostream>
#include"./FDB_LOG.h"
using namespace std;

//----------------------------------LOG_fd------------------------------------------------

//---------------------------------LOG_Buffer--------------------------------------------

LOG_Buffer::LOG_Buffer()
{
    used = 0;
    buffer = new char [LOG_BUFFER_MAX][LOG_SIZE];
}

LOG_Buffer::~LOG_Buffer()
{
    delete [] buffer;
}

bool LOG_Buffer::Buffer_Add(const char *str, int size)
{
    int length = std::strlen(str);
    if (length != size)
    {
        return false;
    }
    int get_mutex;

    bzero(buffer[used], LOG_SIZE);
    memcpy(buffer[used], str, LOG_SIZE);

    used ++;
    if (used == LOG_BUFFER_MAX)
    {
        Buffer_Write();
    }
    return true;
}

bool LOG_Buffer::Buffer_Write()
{
    FILE *fp;

    while (1)
    {
        if (log_fd.mutex_fd.try_lock())
        {
            fp = fopen("LOG_AOF.log", "ab+");
            if (!fp)
            {
                return false;
            }
            for (int i = used-1; i >= 0; i--)
            {
                fprintf(fp, "%s\n", buffer[i]);
            }
            break;
        }
    }
    used = 0;
    fclose(fp);
    log_fd.mutex_fd.unlock();
    return true;
}

//---------------------------------FDB_LOG-----------------------------------------------

bool FDB_LOG::FDB_LOG_ADD(const char *a)
{
    int length = std::strlen(a);
    if(length > LOG_SIZE){
        return false;       
    }
    int get_mutex = 1;
    while (get_mutex)
    {
        for (int id = 0; id < LOG_BUFFER_SIZE; id++)
        {
            if (aof_buffer[id].mutex_buffer.try_lock())
            {
                aof_buffer[id].Buffer_Add(a, length);
                aof_buffer[id].mutex_buffer.unlock();
                get_mutex = 0;
                break;
            }
        }
    }
    return true;
}

bool FDB_LOG::FDB_LOG_Write()
{
    for (int i = 0; i < LOG_BUFFER_SIZE; i++)
    {
        while (1)
        {
            if (aof_buffer[i].mutex_buffer.try_lock())
            {
                break;
            }
        }
        aof_buffer[i].Buffer_Write();
        aof_buffer[i].mutex_buffer.unlock();
    }

    return true;
}

std::vector<std::string> FDB_LOG::FDB_LOG_Read()
{
    std::vector<std::string> a;
    std::string b;
    ifstream fp;

    fp.open("LOG_AOF.log");
    while(getline(fp, b))
    {
        a.push_back(b);
    }
    return a;
}
