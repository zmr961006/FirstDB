/*************************************************************************
	> File Name: FDB_md5test.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月04日 星期三 10时22分01秒
 ************************************************************************/

#include<iostream>
#include"FDB_md5.h"
using namespace std;

std::string md5(const std::string str)
{
    MD5 md5 = MD5(str); 
    return md5.hexdigest();
}
int main(int argc, char *argv[])
{
	cout << "MD5(\"\") = " << md5("")  << endl;
    cout << "MD5(\"admin\") = " << md5("admin") << endl;
    cout << "MD5(\"123456789\") = " << md5("123456") << endl;
    return 0;
	/* 函数输出为：
	MD5("") = d41d8cd98f00b204e9800998ecf8427e
	MD5("admin") = 21232f297a57a5a743894a0e4a801fc3
	MD5("123456") = e10adc3949ba59abbe56e057f20f883e */
}

