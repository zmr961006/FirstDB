/*************************************************************************
	> File Name: FDB_Hash_map_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月09日 星期六 23时22分26秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_String.h"
#include"../server/FDB_Hash_map.h"
#include"../server/FDB_Hash_node.h"
#include"../server/FDB_Hash_pseudo.h"
#include<vector>
#include<string>
using namespace std;

void fun(void)
{
    Hash_map<String> a;
    Hash_node_pseudo<String> b("123","234");
    Hash_node_pseudo<String> c("234","456");
    Hash_node_pseudo<String> e("345","456");
    Hash_node_pseudo<String> f("456","456");
    Hash_node_pseudo<String> g("567","456");
    Hash_node_pseudo<String> d("123","def");

    a.Hash_map_add(b);
    a.Hash_map_add(c);
    a.Hash_map_add(g);
    a.Hash_map_show();
    a.Hash_map_add(e);
a.Hash_map_show();
    a.Hash_map_add(f);

    a.Hash_map_show();
    a.Hash_map_add(d);
    String str("123");
    //cout << "str:" <<a.Hash_map_value(str) << endl;
    //cout << "++++++++++++++++++++++++++++++" << endl;

    //a.Hash_map_show();
    //a.Hash_map_del(d);
    //a.Hash_map_show();
    //a.Hash_map_del(d);
    //a.Hash_map_show();
    //a.Hash_map_destory();
    //a.Hash_map_show();
    
    Hash_node_pseudo<String> t1("qwe","def");
    Hash_node_pseudo<String> t2("wer","def");
    Hash_node_pseudo<String> t3("ert","def");
    Hash_node_pseudo<String> t4("rty","def");
    Hash_node_pseudo<String> t5("tyu","def");
    Hash_node_pseudo<String> t6("yui","def");
    Hash_node_pseudo<String> t7("uio","def");
    Hash_node_pseudo<String> t8("ipp","def");
    Hash_node_pseudo<String> t9("asd","def");
    Hash_node_pseudo<String> t0("sdf","def");
    Hash_node_pseudo<String> t11("gfg","def");
    Hash_node_pseudo<String> t12("hgh","def");
    Hash_node_pseudo<String> t13("hjg","def");
Hash_node_pseudo<String> t14("xy","def");
    a.Hash_map_add(t1);
    a.Hash_map_add(t2);
    a.Hash_map_add(t3);
//a.Hash_map_show();
    a.Hash_map_add(t4);
//a.Hash_map_show();
    a.Hash_map_add(t5);
    a.Hash_map_add(t6);
    a.Hash_map_add(t7);
    a.Hash_map_add(t8);
    a.Hash_map_add(t9);
    a.Hash_map_add(t0);
    a.Hash_map_add(t11);
a.Hash_map_show();
    a.Hash_map_add(t12);
a.Hash_map_show();
a.Hash_map_add(t14);
    a.Hash_map_add(t13);
    a.Hash_map_show();

    a.Hash_map_del(t1);
    a.Hash_map_del(t2);
    a.Hash_map_del(t3);
    a.Hash_map_del(t4);
    a.Hash_map_del(t5);
    a.Hash_map_del(t6);
    a.Hash_map_del(t7);
    a.Hash_map_del(t8);
    a.Hash_map_del(t9);
    a.Hash_map_del(t0);
    a.Hash_map_del(t11);
    a.Hash_map_del(t12);
    a.Hash_map_show();
    a.Hash_map_del(t13);
    a.Hash_map_show();
a.Hash_map_del(b);
a.Hash_map_show();
a.Hash_map_del(c);
a.Hash_map_show();
a.Hash_map_del(e);
a.Hash_map_show();
a.Hash_map_del(f);
a.Hash_map_show();
std::cout << "xy" << std::endl;
a.Hash_map_del(g);
a.Hash_map_show();
}

int main()
{
    //while(1)
    //{
        fun();
    //}
}

