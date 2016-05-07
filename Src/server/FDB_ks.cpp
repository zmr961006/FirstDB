/*************************************************************************
	> File Name: kaisa.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月02日 星期一 14时25分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include"FDB_ks.h"
using namespace std;

/*构造函数*/
passwd::passwd(std::string s, int k)
{
    key = k;
    express = s;
}

/*加密函数*/
void passwd::encryption()
{
    for(auto &x:express)
    {
        x = (char)( (int)(x-97+key)%26 + 97 );
    }
    
}
/*解密函数*/
void passwd::decrypt()
{
    for(auto &x:express)
    {
        x = (char)( (int)(x-97-key)%26 + 97 );
    }
}
void passwd::my_output()
{
    std::cout << express << std::endl;
}
