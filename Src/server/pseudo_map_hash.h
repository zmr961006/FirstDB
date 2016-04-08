/*************************************************************************
	> File Name: Key_val.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月04日 星期一 12时22分41秒
 ************************************************************************/

#ifndef _KEY_VAL_H
#define _KEY_VAL_H

#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include"./FDB_String.h"
#include"./pseudo_node_hash.h"

template <typename T>
class Hash_map_pseudo
{
private:
    std::vector<Hash_node_pseudo<T> > data;
public:
    Hash_map_pseudo() = default;
    ~Hash_map_pseudo() = default;
    void Hash_map_set(const String&  a, const T& b);
    void Hash_map_set(Hash_node_pseudo<T> rhs);
    void Hash_map_del(const String & rhs);
    void Hash_map_change(const String & a, const T & b);
    void Hash_map_change(Hash_node_pseudo<T> rhs);
    bool Hash_map_test(const String & rhs);
    T Hash_map_find(const String & rhs);
    void Hash_map_show();
    int Hash_map_size();
    void Hash_map_destory();
    std::vector<Hash_node_pseudo<T> > Hash_map_data();
};

template <typename T>
void Hash_map_pseudo<T>::Hash_map_set(const String & a, const T & b)
{
    Hash_node_pseudo<T> key_value(a, b);

    if (Hash_map_test(a) == true)
    {
        Hash_map_change(a, b);
    }
    else
    {
        data.push_back(key_value);
    }
}

template <typename T>
void Hash_map_pseudo<T>::Hash_map_set(Hash_node_pseudo<T> rhs)
{
    if (Hash_map_test(rhs.Hash_key()) == true)
    {
        Hash_map_change(rhs);
    }
    else
    {
        data.push_back(rhs);
    }
}

template <typename T>
void Hash_map_pseudo<T>::Hash_map_del(const String & rhs)
{
    for (auto item = data.begin(); item != data.end(); ++item)
    {
        if (rhs == (*item).Hash_key())
        {
            data.erase(item);
            break;
        }
    }
}

template <typename T>
void Hash_map_pseudo<T>::Hash_map_change(const String & a, const T & b)
{
    Hash_map_del(a);
    Hash_map_set(a, b);   
}

template <typename T>
void Hash_map_pseudo<T>::Hash_map_change(Hash_node_pseudo<T> rhs)
{
    Hash_map_del(rhs.Hash_key());
    Hash_map_set(rhs.Hash_key(), rhs.Hash_value());
}

template <typename T>
bool Hash_map_pseudo<T>::Hash_map_test(const String & rhs)
{
    for (auto item : data)
    {
        if (rhs == item.Hash_key())
        {
            return true;
        }
    }
    return false;
}

//在调用Hash_map_find之前必须先调用Hash_map_test测试这个key是否在data中
template <typename T>
T Hash_map_pseudo<T>::Hash_map_find(const String & rhs)
{
    for (auto item : data)
    {
        if ( rhs == item.Hash_key() )
        {
            return item.Hash_value();
        }
    }
}

template <typename T>
void Hash_map_pseudo<T>::Hash_map_show()
{
    for (auto item : data)
    {
        item.Hash_show();
    }
}

template <typename T>
int Hash_map_pseudo<T>::Hash_map_size()
{
    return data.size();
}

template <typename T>
void Hash_map_pseudo<T>::Hash_map_destory()
{
    data.erase(data.begin(), data.end());
}

template <typename T>
std::vector<Hash_node_pseudo<T>> Hash_map_pseudo<T>::Hash_map_data()
{
    return data;
}

#endif
