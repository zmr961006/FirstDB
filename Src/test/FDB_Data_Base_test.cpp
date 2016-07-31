/*************************************************************************
	> File Name: FDB_Hash_map_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月09日 星期六 23时22分26秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_Data_Base.h"
#include"../server/FDB_Key_val.h"
#include<vector>
#include<string>
#include<unistd.h>
using namespace std;

void fun(void)
{
    Data_Base a(4, 10);
    Key_val k("0", 0, 1, 0);
    Key_val k1("1", 0, 1, 0);
    Key_val k2("2", 0, 1, 0);
    Key_val k3("3", 0, 1, 0);
    Key_val k4("4", 0, 1, 0);
    Key_val k5("5", 0, 1, 0);
    Key_val k6("6", 0, 1, 0);
    Key_val k7("7", 0, 1, 0);
    Key_val k8("8", 0, 1, 0);
    Key_val k9("9", 0, 1, 0);
    Key_val k10("10", 0, 1, 0);
    Key_val k11("11", 0, 1, 0);
    Key_val k12("12", 0, 1, 0);
    Key_val k13("13", 0, 1, 0);
    Key_val k14("14", 0, 1, 0);
    Key_val k15("15", 0, 1, 0);
    Key_val k16("16", 0, 1, 0);
    Key_val k17("17", 0, 1, 0);
    Key_val k18("18", 0, 1, 0);
    Key_val k19("19", 0, 1, 0);
    Key_val k20("20", 0, 1, 0);
    Key_val k21("21", 0, 1, 0);
    Key_val k22("22", 0, 1, 0);
    Key_val k23("23", 0, 1, 0);
    Key_val k24("24", 0, 1, 0);
    Key_val k25("25", 0, 1, 0);
    Key_val k26("26", 0, 1, 0);
    Key_val k27("27", 0, 1, 0);
    Key_val k28("28", 0, 1, 0);
    Key_val k29("29", 0, 1, 0);
    Key_val k30("30", 0, 1, 0);
    Key_val k31("31", 0, 1, 0);
    Key_val k32("32", 0, 1, 0);
    Key_val k33("33", 0, 1, 0);
    Key_val k34("34", 0, 1, 0);

    a.Data_Base_add(k);
    a.Data_Base_add(k1);
    a.Data_Base_add(k2);
//a.Data_Base_del(k1.get_key());
    //a.Data_Base_show();
    a.Data_Base_add(k3);
    //a.Data_Base_show();
//std::cout << "q" << std::endl;
    a.Data_Base_add(k4);
//std::cout << "q" << std::endl;
    //a.Data_Base_show();
    a.Data_Base_add(k5);
    a.Data_Base_add(k6);
    a.Data_Base_add(k7);
    a.Data_Base_add(k8);
//a.Data_Base_show();
    a.Data_Base_add(k9);
//a.Data_Base_show();
    a.Data_Base_add(k10);
    a.Data_Base_add(k11);
    a.Data_Base_add(k12);
    a.Data_Base_add(k13);
    a.Data_Base_add(k14);
    a.Data_Base_add(k15);
    a.Data_Base_add(k16);
//a.Data_Base_show();
    a.Data_Base_add(k17);
//a.Data_Base_show();
a.Data_Base_add(k18);
    a.Data_Base_add(k19);
    //a.Data_Base_show();
    a.Data_Base_add(k20);
    a.Data_Base_add(k21);
    a.Data_Base_add(k22);
    a.Data_Base_add(k23);
    a.Data_Base_add(k24);
    a.Data_Base_add(k25);
    a.Data_Base_add(k26);
    a.Data_Base_add(k27);
    a.Data_Base_add(k28);
    a.Data_Base_add(k29);
    a.Data_Base_add(k30);
    a.Data_Base_add(k31);
    //a.Data_Base_show();
    a.Data_Base_add(k32);
    //a.Data_Base_show();
    a.Data_Base_add(k33);
    //a.Data_Base_show();
    a.Data_Base_add(k34);
    //a.Data_Base_show();

    a.Data_Base_del(k1.get_key());
    a.Data_Base_del(k2.get_key());
    a.Data_Base_del(k3.get_key());
    a.Data_Base_del(k4.get_key());
    a.Data_Base_del(k5.get_key());
    a.Data_Base_del(k6.get_key());
    a.Data_Base_del(k7.get_key());
    a.Data_Base_del(k8.get_key());
    a.Data_Base_del(k9.get_key());
    a.Data_Base_del(k.get_key());
    a.Data_Base_del(k10.get_key());
    a.Data_Base_del(k11.get_key());
    a.Data_Base_del(k12.get_key());
    a.Data_Base_del(k13.get_key());
    a.Data_Base_del(k14.get_key());
    a.Data_Base_del(k15.get_key());
    a.Data_Base_del(k16.get_key());
    a.Data_Base_del(k17.get_key());
    a.Data_Base_del(k18.get_key());
    a.Data_Base_del(k19.get_key());
    a.Data_Base_del(k20.get_key());
    a.Data_Base_del(k21.get_key());
    a.Data_Base_del(k22.get_key());
    a.Data_Base_del(k23.get_key());
    a.Data_Base_del(k24.get_key());
    a.Data_Base_del(k25.get_key());
    a.Data_Base_del(k26.get_key());
    a.Data_Base_del(k27.get_key());
    a.Data_Base_del(k28.get_key());
    a.Data_Base_del(k29.get_key());
    a.Data_Base_del(k30.get_key());
    //a.Data_Base_show();
    a.Data_Base_del(k31.get_key());
    //a.Data_Base_show();
    a.Data_Base_del(k32.get_key());
    //a.Data_Base_show();
    a.Data_Base_del(k33.get_key());
    //a.Data_Base_show();
    a.Data_Base_del(k34.get_key());
    //a.Data_Base_show();
//std::cout << "q" << std::endl;
}

int main()
{
    while(1)
    {
        fun();
	usleep(10);
    }
}

