/*************************************************************************
	> File Name: FDB_ks.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月04日 星期三 11时34分49秒
 ************************************************************************/
//
#ifndef _FDB_KS_H
#define _FDB_KS_H
#endif

#include<iostream>
using namespace std;
class passwd
{
public:
    passwd(std::string s, int k);      /*构造函数*/
    passwd() = default;                /*默认构造函数*/
    void encryption();                 /*加密成员函数*/
    void decrypt();                    /*解密成员函数*/
    void my_output();                  /*输出密文或解密后的字符串*/
private:
    int key;                           /*密钥*/
    std::string express;               /*明文字符串*/

};

