/*************************************************************************
	> File Name: FDB_LOG_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月13日 星期三 17时26分23秒
 ************************************************************************/

#include<iostream>
#include<thread>
#include<ctime>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"./FDB_LOG.h"
#include"./FDB_LOG.cpp"
using namespace std;

FDB_LOG a;

void thread_1()
{
    char b[255];
    int i;
    for( i = 0; i < 250; i++)
    {
        b[i] = '1';
    }
    b[i] = 0;

    for (int i = 0; i < 500000; i++)
    {
        a.FDB_LOG_ADD(b);
    }

    a.FDB_LOG_Write(); 
}

int main()
{
    thread t1(thread_1);
    thread t2(thread_1);
    thread t3(thread_1);
    thread t4(thread_1);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
