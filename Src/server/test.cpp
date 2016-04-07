/*************************************************************************
	> File Name: test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月04日 星期一 13时55分38秒
 ************************************************************************/

#include<iostream>
#include"./FDB_String.cpp"
#include"./pseudo_map_hash.h"
#include"./pseudo_node_hash.h"
#include"./hash_map.h"
using namespace std;

int main()
{
    Hash_node_pseudo<String> a;
    int i = 123;
    Hash_node_pseudo<int> b("wrx", i);
    int c;
    String d;
    String j = "hxj";

    a.Hash_set("zmr", j);
    a.Hash_show();
    b.Hash_show();
    c = b.Hash_value();
    d = b.Hash_key();
    c = 2;
    d = "111";
    b.Hash_show();

    Hash_map_pseudo<String> hash;
    Hash_node_pseudo<String> hash1("123","456");
    String str;
    hash.Hash_map_set(a);
    hash.Hash_map_set(j, d);
    cout << hash.Hash_map_size() << endl;
    if ( hash.Hash_map_test(j) == true)
    {
        str = hash.Hash_map_find(j);
        cout << str << endl;
    }
    else
    {
        cout << "don,t find!" << endl;
    }
    hash.Hash_map_show();
    cout << hash.Hash_map_size() << endl;
    hash.Hash_map_set("zmr", "abc");
    hash.Hash_map_show();
    //hash.Hash_map_destory();
    //hash.Hash_map_show();

    cout << "---------------------------------------" << endl;
    
    Hash_map<String> map(hash);
    map.Hash_map_show();
}
