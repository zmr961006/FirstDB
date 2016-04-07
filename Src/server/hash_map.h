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
#include"./FDB_String.h"

#define GET_CHAR(data) data.Hash_key().StringGetChar()

#define HASH_DEFAULT 128
#define HASH_MAP_MAX 64

template <typename T>
class Hash_map
{
private:
    unsigned long used;
    unsigned long mask;
    unsigned long size;
    std::vector<std::list<Hash_node_pseudo<T>>> hash;
    std::vector<std::list<Hash_node_pseudo<T>>> rehash;
    unsigned long reused;
    unsigned long remask;
    unsigned long resize;
    int rehashhidx;
public:
    Hash_map() = default;
    Hash_map(Hash_map_pseudo<T> rhs);
    
    void Hash_map_add(Hash_node_pseudo<T> rhs);
    void Hash_map_show();

    unsigned int GetKey_char(const void *key);
    unsigned int GetKey_int(unsigned int key);
};

template <typename T>
Hash_map<T>::Hash_map(Hash_map_pseudo<T> rhs)
{
    std::vector<Hash_node_pseudo<T>> data = rhs.Hash_map_data();
    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_DEFAULT);

    used = data.size();
    mask = HASH_DEFAULT - 1;
    size = HASH_DEFAULT;
    hash = vec;
    for (auto item : data)
    {
        Hash_map_add(item);
    }

    remask = 0;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
}

template <typename T>
void Hash_map<T>::Hash_map_add(Hash_node_pseudo<T> rhs)
{
    unsigned int key = GetKey_char(GET_CHAR(rhs));
    if (used/size > 1)
    {
        
    }
    else 
    {
        hash[key%size].push_front(rhs);
    }
}

template <typename T>
void Hash_map<T>::Hash_map_show()
{
    std::cout << "hash: " << std::endl;
    std::cout << "size: " << size << "  mask: " << mask << "  used: " << used << std::endl;
    for ( auto item : hash )
    {
        for (auto it : item)
        {
            std::cout << it.Hash_key() << "---" << it.Hash_value() << "---" << it.Get_hash_key() << std::endl;
        }
    }
    
    std::cout << "rehash: " << std::endl;
    std::cout << "resize: " << resize << "  remask: " << remask << "  reused: " << reused << std::endl;
    for ( auto item : rehash )
    {
        for (auto it : item)
        {
            std::cout << it.Hash_key() << "---" << it.Hash_value() << "---" << it.Get_hash_key() << std::endl;
        }
    }
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
