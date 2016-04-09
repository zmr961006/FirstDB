/*************************************************************************
	> File Name: pseudo_hash.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月04日 星期一 12时32分11秒
 ************************************************************************/

#ifndef _PSEUDO_HASH_H
#define _PSEUDO_HASH_H

#include<iostream>
#include<vector>
#include"./FDB_String.h"

template <typename T>
class Hash_node_pseudo
{
private:
    String key;
    T value;
    unsigned int hash_num;
public:
    Hash_node_pseudo() = default;
    Hash_node_pseudo(const String & Key, const T & data);
    ~Hash_node_pseudo() = default;
    void Hash_set(const String &Key, const T & data);
    void Hash_show();
    void Set_hash_key(unsigned int a);
    String Hash_key();
    T Hash_value();
    unsigned int Get_hash_key();
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
