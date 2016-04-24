/*************************************************************************
	> File Name: FDB_info_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 19时01分46秒
 ************************************************************************/

#include<iostream>
#include"./FDB_ctl_info.h"
#include"./FDB_ctl_info.cpp"


int main(){

    Ctl_info info;
    info.read_info();
    info.show_all();



}
