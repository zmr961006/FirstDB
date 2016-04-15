/*************************************************************************
	> File Name: FDB_Hash_node.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月09日 星期六 23时17分03秒
 ************************************************************************/

#ifndef _FDB_HASH_NODE_H
#define _FDB_HASH_NODE_H

#include<iostream>
#include<vector>
#include"./FDB_String.h"

template <typename T>
class Hash_node_pseudo
{
private:
    String key;                 //键值对的键
    T value;                    //键值对的值
    unsigned int hash_num;      //键值对键的hash值
public:
    Hash_node_pseudo() = default; 
    Hash_node_pseudo(const String & Key, const T & data);   //初始化该键值对
    ~Hash_node_pseudo() = default;
    void Hash_set(const String &Key, const T & data);       //向一个键值对写入信息
    void Hash_show();                           //测试时使用的借口，打印键值对的所有信息
    void Set_hash_key(unsigned int a);          //向键值对的hash值写入结果
    String Hash_key();                          //返回键值对的键
    T Hash_value();                             //返回键值对的值
    unsigned int Get_hash_key();                //返回键值对的hash值
};

template <typename T>
Hash_node_pseudo<T>::Hash_node_pseudo(const String & Key, const T & data)
{
    key = Key;
    value = data;
    hash_num = 0;
}

template <typename T>
void Hash_node_pseudo<T>::Hash_set(const String & Key, const T & data)
{
    key = Key;
    value = data;
    hash_num = 0;
}

template <typename T>
void Hash_node_pseudo<T>::Set_hash_key(unsigned int a)
{
    hash_num = a;
}

template <typename T>
void Hash_node_pseudo<T>::Hash_show()
{
    std::cout << key << "------" << value << "------" << hash_num << std::endl;
}

template <typename T>
String Hash_node_pseudo<T>::Hash_key()
{
    return key;
}

template <typename T>
T Hash_node_pseudo<T>::Hash_value()
{
    return value;
}

template <typename T>
unsigned int Hash_node_pseudo<T>::Get_hash_key()
{
    return hash_num;
}

#endif
