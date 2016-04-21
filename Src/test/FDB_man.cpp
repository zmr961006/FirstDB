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
    my_intset v;
    v.my_insert(i);
    v.my_insert(j);
    v.print_int();

    v.my_insert(k);
    v.my_insert(y);
    //v.my_less_sort();
    //v.my_greater_sort();

    std::cout << "hello" << std::endl;
    //v.print_int();
  v.intset_delete(k);
    v.print_int();
/*
    std::cout << v.find_intset(i) << std::endl;
    std::cout << v.find_intset(j) << std::endl;
    std::cout << v.find_intset(k) << std::endl;

*/
    return 0;
}
