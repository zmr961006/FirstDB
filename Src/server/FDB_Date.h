/*************************************************************************
	> File Name: Date.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月21日 星期四 13时10分44秒
 ************************************************************************/

#ifndef _DATE_H
#define _DATE_H

#include<iostream>
#include<ctime>
#include<string>
#include<sys/time.h>
#include<stdio.h>

class Date
{
private:
    char date[30];
    struct timeval tv;
    struct tm *t;
public:
    Date() = default;
    char* Date_time();
};

char* Date::Date_time()
{
    gettimeofday(&tv, NULL);
    t = localtime(&tv.tv_sec);
    snprintf(date, sizeof(date), "%4d年%02d月%02d日 %02d:%02d:%02d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
    return date;
}

#endif
