/*************************************************************************
	> File Name: test1.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月08日 星期五 01时06分01秒
 ************************************************************************/

#include<iostream>
#include"./FDB_String.h"
#include"./FDB_String.cpp"
#include"./hash_map.h"
#include"./pseudo_map_hash.h"
#include"./pseudo_node_hash.h"
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
    a.Hash_map_add(f);

    a.Hash_map_show();
    a.Hash_map_add(d);

    String str("123");
    cout << "str:" <<a.Hash_map_value(str) << endl;
    cout << "++++++++++++++++++++++++++++++" << endl;

    a.Hash_map_show();
    a.Hash_map_del(d);
    a.Hash_map_show();
    a.Hash_map_destory();
    a.Hash_map_show();
}

int main()
{
    //while(1)
    //{
        fun();
    //}
}
