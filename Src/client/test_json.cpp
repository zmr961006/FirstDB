/*************************************************************************
	> File Name: test_json.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年08月11日 星期四 11时53分24秒
 ************************************************************************/

#include<iostream>
#include"FDB_json.h"

using namespace std;
int main(int argc,char *argv[])
{
    fdb_json A;          /*json 类对象A*/
    std::string str;     /*string 串儿*/

    std::string test_str;

    str = A.input_str_tojson();    /*输入以空格隔开的三个字符串，将其转换成一个json格式字符串并返回*/

    std::cout << "json串儿格式为：" << str << std::endl;
    std::cout << '\n' << std::endl;


    test_str = A.json_tostr(str);            /*将json格式的字符串转换成输入时的三个普通字符串*/

    /*获取三个字符串的内容*/
    std::cout << "获取的第1个字符串：" << A.get_comm_name() << std::endl;
    std::cout << "获取的第2个字符串：" << A.get_key() << std::endl;
    std::cout << "获取的第3个字符串：" << A.get_value() << std::endl;
    std::cout << "获取的第4个字符串：" << A.get_jadd() << std::endl;


    std::cout << '\n' << "将json解析成字符串后：" ;
    /*输出三个字符串*/
    A.print_str();
    
    std::cout << "test_str:" << test_str << std::endl;
    return 0;
}
