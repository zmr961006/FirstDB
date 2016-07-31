/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月24日 星期四 10时52分30秒
 ************************************************************************/

#include<iostream>
#include"./FDB_String.h"
using namespace std;

int main()
{
    String a("ssssssss");
    String b;
    char c[10] = "doubiias";

    cout << a << "  size : " << a.getsize() << " free : " << a.getfree() << endl;
    cin >> b;
    cout << b << "  size : " << b.getsize() << " free : " << b.getfree() << endl;
    b = a;
    cout << b << "  size : " << b.getsize() << " free : " << b.getfree() << endl;
    b[0] = '1';
    cout << b << "  size : " << b.getsize() << " free : " << b.getfree() << endl;
    a += b;
    cout << a << "  size : " << a.getsize() << " free : " << a.getfree() << endl;
    cout << (a > b) << " " << (a < b) << " " << (a == b) <<endl;
    a += c;
    cout << a << "  size : " << a.getsize() << " free : " << a.getfree() << endl;
    cout << b << "  size : " << b.getsize() << " free : " << b.getfree() << endl;
    String d = a + b;
    cout << d << "  size : " << d.getsize() << " free : " << d.getfree() << endl;
    d = a + c;
    cout << d << "  size : " << d.getsize() << " free : " << d.getfree() << endl;
    b.StringSizeClear(1,2);
    cout << b << "  size : " << b.getsize() << " free : " << b.getfree() << endl;
    d.StringClear(); 
    cout << d << "  size : " << d.getsize() << " free : " << d.getfree() << endl;

    return 0;
}
