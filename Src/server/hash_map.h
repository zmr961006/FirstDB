/*************************************************************************
	> File Name: hash_map.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月06日 星期三 20时53分20秒
 ************************************************************************/

#ifndef _HASH_MAP_H
#define _HASH_MAP_H

#include<iostream>
#include<list>
#include<vector>
#include"./pseudo_node_hash.h"
#include"./pseudo_map_hash.h"
#include"./FDB_String.h"

#define GET_CHAR(data) data.Hash_key().StringGetChar()

#define HASH_DEFAULT 128
#define HASH_MAP_MAX 64
#define REHASH_DEFAULT 10
#define HASH_MIN 4

template <typename T>
class Hash_map
{
private:
    unsigned long used;
    unsigned long size;
    std::vector<std::list<Hash_node_pseudo<T>>> hash;
    unsigned long reused;
    unsigned long resize;
    std::vector<std::list<Hash_node_pseudo<T>>> rehash;
    int rehashhidx;
public:
    Hash_map();
    Hash_map(Hash_map_pseudo<T> rhs);
    
    void Hash_map_add(Hash_node_pseudo<T> rhs);
    void Hash_map_del(Hash_node_pseudo<T> rhs);
    void Hash_map_change(Hash_node_pseudo<T> rhs);
    void Hash_map_destory();
    void Hash_map_show();
    bool Hash_map_find(Hash_node_pseudo<T> rhs);
    T Hash_map_value(String rhs);

    unsigned int GetKey_char(const void *key);
    unsigned int GetKey_int(unsigned int key);
};

template <typename T>
Hash_map<T>::Hash_map()
{
    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_MIN);

    used = 0;
    size = HASH_MIN;
    hash = vec;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
}

template <typename T>
Hash_map<T>::Hash_map(Hash_map_pseudo<T> rhs)
{
    std::vector<Hash_node_pseudo<T>> data = rhs.Hash_pseudo_data();
    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_DEFAULT);

    used = 0;
    size = HASH_DEFAULT;
    hash = vec;
    
    reused = 0;
    resize = 0;
    rehashhidx = -1;

    for (auto item : data)
    {
        Hash_map_add(item);
    }
}

template <typename T>
void Hash_map<T>::Hash_map_add(Hash_node_pseudo<T> rhs)
{
    if (Hash_map_find(rhs) == true)
    {
        Hash_map_change(rhs);
        return ;
    }

    unsigned int key = GetKey_char(GET_CHAR(rhs));
    rhs.Set_hash_key(key);
    
    if ((rehashhidx == -1) && (used/size >= 1))
    {
        rehashhidx = 0;
        resize = size * 2;
        reused = 0;
        std::vector<std::list<Hash_node_pseudo<T>>> vec_rehash(resize);
        rehash = vec_rehash;
    }

    if (rehashhidx != -1)
    {
        rehash[key%resize].push_front(rhs);
        reused++;

        int i = 0;
        int sum = 0;
        while (1)
        {
            while (hash[i].size() != 0)
            {
                auto item = hash[i].begin();
                rehash[(*item).Get_hash_key() % resize].push_front(*item);
                hash[i].erase(item);
                reused++;
                rehashhidx++;
                used--;
            }
            if ( (++sum > REHASH_DEFAULT) || (rehashhidx == size))
            {
                break;
            }
            i++;
        }
    }
    else 
    {
        hash[key%size].push_front(rhs);
        used++;
    }
    
    if (rehashhidx == size)
    {
        rehashhidx = -1;
        hash = rehash;
        used = reused;
        size = resize;
        reused = 0;
        resize = 0;
        std::vector<std::list<Hash_node_pseudo<T>>>().swap(rehash);
    }
}

template <typename T>
void Hash_map<T>::Hash_map_destory()
{
    std::vector<std::list<Hash_node_pseudo<T>>>().swap(hash);
    std::vector<std::list<Hash_node_pseudo<T>>>().swap(rehash);

    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_MIN);

    used = 0;
    size = HASH_MIN;
    hash = vec;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
}

template <typename T>
bool Hash_map<T>::Hash_map_find(Hash_node_pseudo<T> rhs)
{
    unsigned int key = GetKey_char(GET_CHAR(rhs));
    for (auto item : hash[key % size])
    {
        if (rhs.Hash_key() == item.Hash_key())
        {
            return true;
        }
    }
    
    if (rehashhidx != -1)
    {
        for (auto item : rehash[key % resize])
        {
            if (rhs.Hash_key() == item.Hash_key())
            {
                return true;
            }
        }
    }

    return false;
}

template <typename T>
void Hash_map<T>::Hash_map_del(Hash_node_pseudo<T> rhs)
{
    if (Hash_map_find(rhs) == false)
    {
        return;
    }

    unsigned int hash_key = GetKey_char(GET_CHAR(rhs));
    auto item = hash[hash_key % size].begin();
    while(item != hash[hash_key % size].end())
    {
        if (rhs.Hash_key() == (*item).Hash_key())
        {
            hash[hash_key % size].erase(item);
            return;
        }
        else 
        {  
            item ++;
        }
    }
    
    if (rehashhidx != -1)
    {
        auto item = rehash[hash_key % resize].begin();
        while(item != rehash[hash_key % resize].end())
        {
            if (rhs.Hash_key() == (*item).Hash_key())
            {
                hash[hash_key % resize].erase(item);
                return;
            }
            else
            {
                item++;
            }
        }
    }
}

template <typename T>
void Hash_map<T>::Hash_map_change(Hash_node_pseudo<T> rhs)
{
    Hash_map_del(rhs);
    Hash_map_add(rhs);
}

template <typename T>
T Hash_map<T>::Hash_map_value(String rhs)
{
    unsigned int key = GetKey_char(rhs.StringGetChar());
    for (auto item : hash[key % size])
    {
        if (rhs == item.Hash_key())
        {
            return item.Hash_value();
        }
    }
    if (rehashhidx != -1)
    {
        for (auto item : rehash[key % resize])
        {
            if (rhs == item.Hash_key())
            {
                return item.Hash_value();
            }
        }
    }
}

template <typename T>
void Hash_map<T>::Hash_map_show()
{
    std::cout << "hash: " << std::endl;
    std::cout << "size: " << size << "  used: " << used << "  hash_size: " << hash.size() << std::endl;
    int i = 0;
    for ( auto item : hash )
    {
        for (auto it : item)
        {
            std::cout << i << " :" << std::endl;
            std::cout << it.Hash_key() << "---" << it.Hash_value() << "---" << it.Get_hash_key() << std::endl;
        }
        i++;
    }
    
    std::cout << "rehash: " << std::endl;
    std::cout << "resize: " << resize << "  reused: " << reused << "  rehash_size: " << rehash.size() << std::endl;
    i = 0;
    for ( auto item : rehash )
    {
        for (auto it : item)
        {
            std::cout << i << " :" << std::endl;
            std::cout << it.Hash_key() << "---" << it.Hash_value() << "---" << it.Get_hash_key() << std::endl;
        }
        i++;
    }
    std::cout << "rehashhidx: " << rehashhidx << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
}

template <typename T>
unsigned int Hash_map<T>::GetKey_int(unsigned int key){
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3 );
    key ^=  (key >> 6 );
    key += ~(key << 11);
    key ^=  (key >> 16);
    return key;
}

template <typename T>
unsigned int Hash_map<T>::GetKey_char(const void *key){
    uint32_t seed = 5635;
    const uint32_t m = 0x5bd1e995;
    const int r = 24;
    int len = 8;
    uint32_t h = seed ^ len;
    const unsigned char * data = (const unsigned char *)key;
    
    while(len >= 4){
        uint32_t k = *(uint32_t *)data;

        k *= m;
        k ^= k >> r;
        k *= m;
        h *= m;
        h ^= k;
        
        data += 4;
        len -=  4;
    }

    switch(len){
        case 3: h ^= data[2] << 16;
        case 2: h ^= data[1] << 8 ;
        case 1: h ^= data[0]; h *= m;
    };

    h ^= h >> 13;
    h *= m;
    h ^= h >> 15;

    return (unsigned int )h;
}

#endif
