/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年05月04日 星期三 14时51分31秒
 ************************************************************************/

#include<iostream>
using namespace std;
#include"./FDB_json.h"

int main(){

    std::string key = "hello";
    std::string val = "value";
    std::string opr = "add"  ;
    JSon test(key,opr,10,10,opr);
    std::cout <<  test.Json_get_key() << std::endl;


}
