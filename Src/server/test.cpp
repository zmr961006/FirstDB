/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月15日 星期五 21时19分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

#include"./FDB_Socket.h"
#include"./FDB_Socket.cpp"

int main(){

    Socket a(AF_INET,10);
    std::cout << a.fd() << std::endl;




}
