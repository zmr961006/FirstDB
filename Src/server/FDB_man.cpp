/*************************************************************************
	> File Name: intset.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年04月17日 星期日 16时27分26秒
 ************************************************************************/


#include<iostream>
#include<vector>

using namespace std;
#include"FDB_intset.h"

int main(int argc,char *argv[])
{
    short i = 3;
    int j = 1;
    long k = 2;

    long y = 4;

    std::string s = "my name is hxj";
    std::string e = "my";

    my_intset v;         /*定义测试对象*/
    v.my_insert(i);      /*向集合里面插入元素*/
    v.my_insert(j);

    v.print_int();       /*输出集合中的元素*/

    v.my_insert(k);
    v.my_insert(y);
    v.my_insert(s);
    v.my_insert(e);


    v.my_less_sort();    /*给集合中的元素按升序整体排序*/

    /*v.my_greater_sort();*/

    std::cout << "hello" << std::endl;
    /*v.intset_delete(s);*/

    v.print_int();
    /*std::cout << v.find_intset(s) << std::endl;*/
    /*std::cout << v.get_bit_size() << std::endl;*/
    return 0;
}
