/*************************************************************************
	> File Name: test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月21日 星期四 17时34分01秒
 ************************************************************************/

#include<iostream>
#include"./FDB_user.h"
#include"./FDB_user.cpp"
#include"./FDB_accept.h"
#include"./FDB_accept.cpp"
using namespace std;

User a;

void func()
{
    Accept b(1);
    a.User_add(b);
}

int main()
{
    for (int i = 0; i <100; i++)
    {
        func();
    }
a.User_find(1);
    
}
