/*************************************************************************
    > File Name: FDB_Data_All_test.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年07月27日 星期三 19时09分18秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_Data_All.h"
#include"../server/FDB_Data_Base.h"
#include"../server/FDB_Data_All.cpp"
#include"../server/FDB_Data_Base.cpp"
#include"../server/FDB_Key_val.cpp"
#include"../server/FDB_Key_val.h"
#include"../server/FDB_String.h"
#include"../server/FDB_String.cpp"
#include<vector>
#include<string>
#include<unistd.h>
using namespace std;

void fun2()
{
    Data_All da(16,4,4);
    da.Add("wrx", "123", 0, "abc");
    da.Add("wrx", "456", 0, "def");
    da.Add("wrx", "789", 0, "ghi");
    da.Add("wrx", "999", 0, "ghi");
    da.Val_Del("wrx", 0, "123");
    //da.Del("wrx", 0);
    if (da.Find("wrx") == false)
        return;
    const char * a;
    a = da.Value("wrx",0);
    cout << a << endl;
}

void fun3()
{
    Data_All da(16,4,4);
    da.Add("wrx", "123", 3);
    const char *a;
    a = da.Value("wrx", 3);
    cout << a << endl;
}

int main()
{
     while (1)
     {
         fun3();
         usleep(10);
     }
    fun3();
}