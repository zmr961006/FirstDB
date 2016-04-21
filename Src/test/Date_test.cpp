/*************************************************************************
	> File Name: Date_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月21日 星期四 13时11分30秒
 ************************************************************************/

#include<iostream>
#include"./Date.h"
using namespace std;

int main()
{
    Date d;
    cout << d.Date_time() << endl;
    string s = d.Date_time();
    cout << s << endl;
}
