/*************************************************************************
    > File Name: FDB_Data_All_test.cpp
    > Author: 
    > Mail: 
    > Created Time: 2016年07月27日 星期三 19时09分18秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_Data_All.h"
#include"../server/FDB_Data_Base.h"
#include"../server/FDB_Key_val.h"
#include<vector>
#include<string>
#include<unistd.h>
using namespace std;

void fun()
{
    string key("wrx");

    string a("aaa");
    string b("bbb");
    string c("ccc");
    string d("ddd");
    string e("eee");
    string f("fff");
    string g("ggg");
    string h("hhh");
    string i("iii");
    Data_All da(16,4,4);
    String a1("1");
String b1("2");
String c1("3");
String d1("4");
String e1("5");
String f1("6");
String g1("7");
String h1("8");
String i1("9");
    Hash_node_pseudo<string> a2(a1,a);
Hash_node_pseudo<string> b2(b1,b);
Hash_node_pseudo<string> c2(c1,c);
Hash_node_pseudo<string> d2(d1,d);
Hash_node_pseudo<string> e2(e1,e);
Hash_node_pseudo<string> f2(f1,f);
Hash_node_pseudo<string> g2(g1,g);
Hash_node_pseudo<string> h2(h1,h);
Hash_node_pseudo<string> i2(i1,i);

    void *obj;
    obj = new Hash_node_pseudo<string>;
void *buff = new vector<Hash_node_pseudo<std::string>>;
    (*(Hash_node_pseudo<string> *) obj) = a2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = b2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = c2;
    da.Data_All_add(key, obj, 0);
    da.Data_All_value(key, 0, buff);
cout << (*(vector<Hash_node_pseudo<std::string>> *)buff).size() << endl;
    for (auto item : (*(vector<Hash_node_pseudo<std::string>> *)buff) )
    {
        cout << "11" << endl;
    	item.Hash_show();
    }
    (*(Hash_node_pseudo<string> *) obj) = d2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = e2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = f2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = g2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = h2;
    da.Data_All_add(key, obj, 0);
    (*(Hash_node_pseudo<string> *) obj) = i2;
//(*(Hash_node_pseudo<string> *) obj).Hash_show();
    da.Data_All_add(key, obj, 0);

    da.Data_All_value(key, 0, buff);
cout << (*(vector<Hash_node_pseudo<std::string>> *)buff).size() << endl;
    for (auto item : (*(vector<Hash_node_pseudo<std::string>> *)buff) )
    {
        cout << "11" << endl;
    	item.Hash_show();
    }
da.Data_All_destory(0);
if (da.Data_All_value(key, 0, buff) == false)
{
    cout << "false" << endl;
    delete (vector<Hash_node_pseudo<std::string>> *) buff;
buff = new vector<Hash_node_pseudo<std::string>>;
    
}
da.Data_All_show();

cout << (*(vector<Hash_node_pseudo<std::string>> *)buff).size() << endl;
    for (auto item : (*(vector<Hash_node_pseudo<std::string>> *)buff) )
    {
        cout << "11" << endl;
    	item.Hash_show();
    }
//cout << "111" << endl;
//(*(Hash_node_pseudo<string> *) obj).Hash_show();
    delete (Hash_node_pseudo<string> *) obj;
    delete (vector<Hash_node_pseudo<std::string>> *) buff;
}

int main()
{
    /*while (1)
    {
        fun();
        usleep(10);
    }*/
    fun();
}
