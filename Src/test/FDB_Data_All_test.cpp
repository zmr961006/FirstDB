/*************************************************************************
    > File Name: FDB_Data_All_test.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年07月27日 星期三 19时09分18秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_Data_All.h"
#include"../server/FDB_Data_All.cpp"
#include"../server/FDB_Data_Base.h"
#include"../server/FDB_Data_Base.cpp"
#include"../server/FDB_Key_val.h"
#include"../server/FDB_Key_val.cpp"
#include"../server/FDB_String.cpp"
#include"../server/FDB_String.h"
#include<vector>
#include<string>
#include<unistd.h>
using namespace std;


void fun3()
{
    Data_All da(16,4,4);
    char * a;
    a = da.handle("SET", "wrx", "123", "\0");
    cout << a << endl;
    a = da.handle("GET", "wrx", "\0", "\0");
    cout << a << endl;
    a = da.handle("DEL", "wrx", "\0", "\0");
    cout << a << endl;
    a = da.handle("GET", "wrx", "\0", "\0");
    cout << a << endl;
    delete a;
}

int main()
{
    //  while (1)
    //  {
    //      fun3();
    //      usleep(10);
    //  }
     fun3();
}
