/*************************************************************************
	> File Name: FDB_Ziplist_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月10日 星期日 17时22分09秒
 ************************************************************************/

#include<iostream>
#include"./FDB_ziplist.h"
using namespace std;

int main()
{
    Ziplist<int> a;
    Ziplist<char> b;

    a.Ziplist_add(1);
    a.Ziplist_add(2);
    a.Ziplist_add(3);
    a.Ziplist_add(4);
    a.Ziplist_add(5);
    a.Ziplist_add(6);
    a.Ziplist_show();
    a.Ziplist_del(1);
    a.Ziplist_show();
    a.Ziplist_del_more(2, 4);
    a.Ziplist_show();
    cout << "size: " << a.Ziplist_size() << endl;
    cout << "size_bytes: " <<a.Ziplist_size_bytes() << endl;

    b.Ziplist_add('1');
    cout << "size: " << b.Ziplist_size() << endl;
    cout << "size_types: " << b.Ziplist_size_bytes() << endl;

    if (b.Ziplist_find('b'))
    {
        cout << "oh, my god!" << endl;
    }

    vector<int> c;
    c = a.Ziplist_return();
    cout << c[0] << endl;
    cout << c[1] << endl;
    a.Ziplist_destory();
    cout << "size: " << a.Ziplist_size() << endl;
    cout << "size_bytes: " <<a.Ziplist_size_bytes() << endl;

    return 0;
}
