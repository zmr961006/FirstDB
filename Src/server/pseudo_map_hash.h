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
    void Hash_pseudo_set(const String&  a, const T& b);
    void Hash_pseudo_set(Hash_node_pseudo<T> rhs);
    void Hash_pseudo_del(const String & rhs);
    void Hash_pseudo_change(const String & a, const T & b);
    void Hash_pseudo_change(Hash_node_pseudo<T> rhs);
    bool Hash_pseudo_test(const String & rhs);
    T Hash_pseudo_find(const String & rhs);
    void Hash_pseudo_show();
    int Hash_pseudo_size();
    void Hash_pseudo_destory();
    std::vector<Hash_node_pseudo<T> > Hash_pseudo_data();
};

template <typename T>
void Hash_map_pseudo<T>::Hash_pseudo_set(const String & a, const T & b)
{
    Hash_node_pseudo<T> key_value(a, b);

    if (Hash_pseudo_test(a) == true)
    {
        Hash_pseudo_change(a, b);
    }
    else
    {
        data.push_back(key_value);
    }
}

template <typename T>
void Hash_map_pseudo<T>::Hash_pseudo_set(Hash_node_pseudo<T> rhs)
{
    if (Hash_pseudo_test(rhs.Hash_key()) == true)
    {
        Hash_pseudo_change(rhs);
    }
    else
    {
        data.push_back(rhs);
    }
}

template <typename T>
void Hash_map_pseudo<T>::Hash_pseudo_del(const String & rhs)
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
void Hash_map_pseudo<T>::Hash_pseudo_change(const String & a, const T & b)
{
    Hash_pseudo_del(a);
    Hash_pseudo_set(a, b);   
}

template <typename T>
void Hash_map_pseudo<T>::Hash_pseudo_change(Hash_node_pseudo<T> rhs)
{
    Hash_pseudo_del(rhs.Hash_key());
    Hash_pseudo_set(rhs.Hash_key(), rhs.Hash_value());
}

template <typename T>
bool Hash_map_pseudo<T>::Hash_pseudo_test(const String & rhs)
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
T Hash_map_pseudo<T>::Hash_pseudo_find(const String & rhs)
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
void Hash_map_pseudo<T>::Hash_pseudo_show()
{
    for (auto item : data)
    {
        item.Hash_show();
    }
}

template <typename T>
int Hash_map_pseudo<T>::Hash_pseudo_size()
{
    return data.size();
}

template <typename T>
void Hash_map_pseudo<T>::Hash_pseudo_destory()
{
    data.erase(data.begin(), data.end());
}

template <typename T>
std::vector<Hash_node_pseudo<T>> Hash_map_pseudo<T>::Hash_pseudo_data()
{
    return data;
}

#endif
