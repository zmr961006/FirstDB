/*************************************************************************
	> File Name: FDB_Key_val_test.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年05月04日 星期三 22时08分14秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_Key_val.h"
#include"../server/FDB_Hash_node.h"
#include<unistd.h>
#include<string>
using namespace std;

/*void func()
{
    Key_val k("123", 0, 1, 0);
    void *obj;
    Hash_node_pseudo<string> a("wrx", "19");
Hash_node_pseudo<string> a1("wr1", "18");
Hash_node_pseudo<string> a2("wr2", "17");
Hash_node_pseudo<string> a3("wr3", "");

obj = new Hash_node_pseudo<string>;

(*(Hash_node_pseudo<string>*)obj) = a3;
if(k.Key_val_del(obj) == false)
{
    cout << "error" << endl;
}

(*(Hash_node_pseudo<string>*)obj) = a;
    k.Key_val_add(obj);

(*(Hash_node_pseudo<string>*)obj) = a3;
if(k.Key_val_del(obj) == false)
{
    cout << "error" << endl;
}

(*(Hash_node_pseudo<string>*)obj) = a1;
    k.Key_val_add(obj);

(*(Hash_node_pseudo<string>*)obj) = a2;
    k.Key_val_add(obj);
delete (Hash_node_pseudo<string> *) obj;
void *buff;
buff = new vector<Hash_node_pseudo<string>> ;
k.Key_val_value(buff);
for (auto item : (*(vector<Hash_node_pseudo<string>>*) buff))
{
    item.Hash_show();
}

cout << k.Key_val_size() << endl;

k.Key_val_destory();
cout << k.Key_val_size() << endl;

    //delete (Hash_node_pseudo<string> *) obj;
    delete (vector<Hash_node_pseudo<string>> *) buff;
    cout << k.get_type() << endl;
    cout << k.get_hash() << endl;
    cout << k.get_key() << endl;
}*/

/*void func1()
{
    void *obj;
    Hash_node_pseudo<string> a("wrx", "19");
    obj = new Hash_node_pseudo<string>;
    (*(Hash_node_pseudo<string>*)obj) = a;
    delete (Hash_node_pseudo<string> *) obj; 
//内存泄漏
}*/

/*void func2()
{
    void *obj;
    String a = "100";
    obj = new String;
    delete (String *)obj;
}*/

void func3()
{
    Key_val k("123", 0, 0, 0);
void *obj;
Hash_node_pseudo<string> a("wrx", "19");
Hash_node_pseudo<string> a1("wr1", "18");
Hash_node_pseudo<string> a2("wr2", "17");
Hash_node_pseudo<string> a3("wr3", "16");
Hash_node_pseudo<string> a4("wr4", "19");
Hash_node_pseudo<string> a5("wr5", "18");
Hash_node_pseudo<string> a6("wr6", "17");
Hash_node_pseudo<string> a7("wr7", "16");

obj = new Hash_node_pseudo<string>;

(*(Hash_node_pseudo<string>*)obj) = a;
if(k.Key_val_del(obj) == false)
{
    //cout << "error1" << endl;
}

(*(Hash_node_pseudo<string>*)obj) = a;
k.Key_val_add(obj);
//cout << k.Key_val_size() << endl;
//cout << k.get_type() << endl;

k.Key_val_destory();

(*(Hash_node_pseudo<string>*)obj) = a;
if(k.Key_val_del(obj) == false)
{
    //cout << "error2" << endl;
}

(*(Hash_node_pseudo<string>*)obj) = a1;
    k.Key_val_add(obj);
(*(Hash_node_pseudo<string>*)obj) = a2;
    k.Key_val_add(obj);
(*(Hash_node_pseudo<string>*)obj) = a3;
    k.Key_val_add(obj);

k.Key_val_destory();

(*(Hash_node_pseudo<string>*)obj) = a4;
    k.Key_val_add(obj);
(*(Hash_node_pseudo<string>*)obj) = a5;
    k.Key_val_add(obj);
(*(Hash_node_pseudo<string>*)obj) = a6;
    k.Key_val_add(obj);
(*(Hash_node_pseudo<string>*)obj) = a7;
    k.Key_val_add(obj);
//cout << k.Key_val_size() << endl;
//cout << k.get_type() << endl;

k.Key_val_destory();

delete (Hash_node_pseudo<string> *) obj;

}

/*void func4()
{
   Key_val k("123", 0, 2, 0);
   string a("1");
   string a1("2");
   string a2("3");
   string a3("4");
   string a4("5");
	
   void *obj;
   void *buff;

   obj = new string;
   (*(string *)obj) = a;
   k.Key_val_add(obj);
   (*(string *)obj) = a1;
   k.Key_val_add(obj);

(*(string *)obj) = a2;   
k.Key_val_add(obj); 

(*(string *)obj) = a3;
k.Key_val_add(obj);

(*(string *)obj) = a4;   
k.Key_val_add(obj);

k.Key_val_del(obj);

cout << k.Key_val_size() << endl;

buff = new vector<string>;
k.Key_val_value(buff);
for (auto item : (*(vector<string>*)buff))
{
    cout << item << endl;
}
delete (vector<string> *) buff;
buff = new vector<string>;
k.Key_val_value(buff);
for (auto item : (*(vector<string>*)buff))
{
    cout << item << endl;
}
delete (vector<string> *) buff;
k.Key_val_destory();
cout << k.Key_val_size() << endl;
buff = new vector<string>;
k.Key_val_value(buff);
for (auto item : (*(vector<string>*)buff))
{
    cout << item << endl;
}

delete (string *)obj;
delete (vector<string> *) buff;

}*/

/*void func5()
{
    String a("123");
    void *obj;
    obj = new String;
    (*(String *) obj) = a;
    Key_val k("123", 0, 3, 0);
k.Key_val_add(obj);
   
    delete (String *)obj;

    void *buff;
    buff = new String;

    k.Key_val_value(buff);

    //cout << (*(String *)buff) << endl;
    
    delete (String *)buff;
 
}*/

void func6()
{
    Key_val k("123", 0, 4, 0);
    string a("1");
string a1("2");
string a2("3");
string a3("4");
string a4("5");
    void *obj;
    obj = new string;
    (*(string *)obj) = a;
    k.Key_val_add(obj);
(*(string *)obj) = a1;
k.Key_val_add(obj);
(*(string *)obj) = a2;
k.Key_val_add(obj);
(*(string *)obj) = a3;
k.Key_val_add(obj);
(*(string *)obj) = a4;
k.Key_val_add(obj);
void *buff;
buff = new string;
k.Key_val_value(buff);
cout << (*(string *)buff) << endl;
k.Key_val_del(obj);
k.Key_val_value(buff);
cout << (*(string *)buff) << endl;
cout << k.Key_val_size() << endl;
k.Key_val_destory();
cout << k.Key_val_size() << endl;
delete (string *) obj;
delete (string *) buff;  
}

void func7()
{
    Key_val k("123", 0, 5, 0);
    string a("1");
string a1("2");
string a2("3");
string a3("4");
string a4("5");
    void *obj;
    obj = new string;

    (*(string *)obj) = a;
    k.Key_val_add(obj);
(*(string *)obj) = a1;
k.Key_val_add(obj);
(*(string *)obj) = a2;
k.Key_val_add(obj);
(*(string *)obj) = a3;
k.Key_val_add(obj);
(*(string *)obj) = a4;
k.Key_val_add(obj);
//cout << k.Key_val_size() << endl;
void *buff;
buff = new string;
k.Key_val_value(buff);
//cout << (*(string *)buff) << endl;
k.Key_val_del(obj);
k.Key_val_value(buff);
//cout << (*(string *)buff) << endl;
//cout << k.Key_val_size() << endl;
k.Key_val_destory();
//cout << k.Key_val_size() << endl;
delete (string *)obj;
delete (string *)buff;
}


int main()
{
    while(1)
    {
	//func();
	func7 ();
	usleep(10);
    }
//func3();
}
