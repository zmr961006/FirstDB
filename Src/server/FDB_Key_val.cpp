/*************************************************************************
	> File Name: FDB_Key_val.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 21时59分20秒
 ************************************************************************/

#include<iostream>
#include"./FDB_Key_val.h"

using namespace std;

Key_val::Key_val(std::string key_name, void *obj, unsigned int hash, int type_data, int elem)
{
    key = key_name;
    type  = type_data;
    hash_key = hash;
    cut_time = -1;
    Server_ID = elem;
    /*obj*/
    if (type_data == Hash_Map_NUM)
    {
        value = new Hash_map<std::string> ;
    }
    /*obj*/
}

/*Key_val::~Key_val()
{
    delete (void *)value;
}*/

void Key_val::Key_val_add(char *key_a, std::string value_b)
{
    if (type == Hash_Map_NUM)
    {
        //Hash_map_add(Hash_node_pseudo<T> rhs);
        String b = key_a;
        Hash_node_pseudo<string> a(b, value_b);
        //(*(Hash_map<string> *)value).Hash_map_add(*(Hash_node_pseudo<string>*)obj);
        (*(Hash_map<string> *)value).Hash_map_add(a);
        std::cout << "++++++++" << std::endl;
        (*(Hash_map<string> *)value).Hash_map_show();
    }
}

void Key_val::add_cut_time(long long time)
{
    add_cut_ptime(1000 * time);
}

void Key_val::add_cut_ptime(long long time)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    time += (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    set_cut_ptime(time);
}

void Key_val::set_cut_time(long long time)
{
    set_cut_ptime(time * 1000);
}

void Key_val::set_cut_ptime(long long time)
{
    cut_time = time;
}

void Key_val::set_hash_key(unsigned int hash)
{
    hash_key = hash;
}

int Key_val::get_type()
{
    return type;
}

unsigned int Key_val::get_hash()
{
    return hash_key;
}

std::string Key_val::get_key()
{
    return key;
}

long long Key_val::get_cut_time()
{
    return cut_time;
}
