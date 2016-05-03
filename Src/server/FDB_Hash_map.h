/*************************************************************************
	> File Name: FDB_Hash_map.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月09日 星期六 23时16分54秒
 ************************************************************************/

#ifndef _FDB_HASH_MAP_H
#define _FDB_HASH_MAP_H

#include<iostream>
#include<list>
#include<vector>
#include"./FDB_Hash_node.h"
#include"./FDB_Hash_pseudo.h"
#include"./FDB_String.h"

#define GET_CHAR(data) data.Hash_key().StringGetChar()      
//返回Hash_node_pseudo中键只对中键的char*类型

#define HASH_DEFAULT 128        //由伪哈希向哈希转换时哈希表的大小
#define REHASH_DEFAULT 10       //每次渐近式哈希，由hash向rehash转换的个数
#define HASH_MIN 4              //创建空哈希表时的哈希表大小

template <typename T>
class Hash_map
{
private:
    unsigned long used;         //键值对保存在hash表中的大小
    unsigned long size;         //hash表的大小
    std::vector<std::list<Hash_node_pseudo<T>>> hash;   //hash表的实现
    unsigned long reused;       //键值对保存在rehash表中的大小
    unsigned long resize;       //rehash表的大小
    std::vector<std::list<Hash_node_pseudo<T>>> rehash; //rehash表的实现
    int rehashhidx;             //标志rehash是否使用（-1的代表未使用）
public:
    Hash_map();                 //初始化空哈希表
    Hash_map(Hash_map_pseudo<T> rhs);       //由伪哈希表向哈希表的转换（包括其内键值对的移动）
    
    void Hash_map_add(Hash_node_pseudo<T> rhs);     //向哈希表添加键值对
    void Hash_map_del(Hash_node_pseudo<T> rhs);     //删除哈希表中的键值对rhs
//由hash向rehash渐近式哈希的迁移，包括当hash表迁移完所有后将用rehash代替hash，并将新的rehash置空
    void Hash_map_rehash();                         
    void Hash_map_change(Hash_node_pseudo<T> rhs);  //将与rhs键值对的键相等的键值对替换为rhs
    void Hash_map_destory();                        //清空哈希表，并再次初始化它
    void Hash_map_show();                           //测试函数，打印哈希表的数据
    bool Hash_map_find(Hash_node_pseudo<T> rhs);    //测试rhs键值对是否存在在哈希表中
    T Hash_map_value(String rhs);                   //返回哈希表中键位rhs的键值对的值
    std::vector<Hash_node_pseudo<T>> Hash_map_all();  //将所有结点保存到vector容器中返回
    int Hash_map_size();                            //返回使用大小

    unsigned int GetKey_char(const void *key);      //hash函数
    unsigned int GetKey_int(unsigned int key);      //hash函数
};

template <typename T>
Hash_map<T>::Hash_map()
{
    //初始化一个大小为HASH_MIN的hash表
    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_MIN);

    used = 0;
    size = HASH_MIN;
    //用vec来对hash进行初始化
    hash = vec;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
}

template <typename T>
Hash_map<T>::Hash_map(Hash_map_pseudo<T> rhs)
{
    //data为包含了伪哈希的所有键值对的容器
    std::vector<Hash_node_pseudo<T>> data = rhs.Hash_pseudo_data();
    //初始化一个大小为HASH_DEFAULT的表
    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_DEFAULT);

    used = 0;
    size = HASH_DEFAULT;
    hash = vec;
    
    reused = 0;
    resize = 0;
    rehashhidx = -1;

    //将伪哈希中的键值对添加到hash表中
    for (auto item : data)
    {
        Hash_map_add(item);
    }
}

template <typename T>
void Hash_map<T>::Hash_map_rehash()
{
    int i = 0;
    int sum = 0;
    //实现了键值对从hash向rehash的迁移
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

    //若迁移完成，则用rehash代替hash，并创建新的rehash
    if (used == 0)
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
void Hash_map<T>::Hash_map_add(Hash_node_pseudo<T> rhs)
{
    if (Hash_map_find(rhs) == true)
    {
        Hash_map_change(rhs);
        return ;
    }

    unsigned int key = GetKey_char(GET_CHAR(rhs));
    rhs.Set_hash_key(key);
    
    //当hash表的用量大于hash表大小的时候，启用rehash
    if ((rehashhidx == -1) && (used/size >= 1))
    {
        rehashhidx = 0;
        resize = size * 2;
        reused = 0;
        std::vector<std::list<Hash_node_pseudo<T>>> vec_rehash(resize);
        rehash = vec_rehash;
    }

    //标志不为-1，代表rehash正在使用，将数据添加到rehash表中，并进行数据迁移
    if (rehashhidx != -1)
    {
        rehash[key%resize].push_front(rhs);
        reused++;
        
        Hash_map_rehash();
    }
    else 
    {
        hash[key%size].push_front(rhs);
        used++;
    } 
}

template <typename T>
void Hash_map<T>::Hash_map_destory()
{
    //用swap的方法对vector容器进行销毁工作（因为clear函数无法减少容器进行的预分配）
    std::vector<std::list<Hash_node_pseudo<T>>>().swap(hash);
    std::vector<std::list<Hash_node_pseudo<T>>>().swap(rehash);

    //重新对hash表进行初始化
    std::vector<std::list<Hash_node_pseudo<T>>> vec(HASH_MIN);

    used = 0;
    size = HASH_MIN;
    hash = vec;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
}


//每次Hash_map_find函数前需要该函数返回true位前置条件
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
    
    //若hash表大小是使用量的十倍则用rehash表进行对hash表减少空间的操作
    if ((size/used >= 10) && (rehashhidx == -1))
    {
        rehashhidx = 0;
        resize = size / 2;
        reused = 0;
        std::vector<std::list<Hash_node_pseudo<T>>> vec_rehash(resize);
        rehash = vec_rehash;
    }

    //在rehash表中进行delete操作
    if (rehashhidx != -1)
    {
        auto item = rehash[hash_key % resize].begin();
        while(item != rehash[hash_key % resize].end())
        {
            if (rhs.Hash_key() == (*item).Hash_key())
            {
                hash[hash_key % resize].erase(item);
                reused--;
                return;
            }
            else
            {
                item++;
            }
        }
        Hash_map_rehash();
    }

    //在hash表中进行delete操作
    auto item = hash[hash_key % size].begin();
    while(item != hash[hash_key % size].end())
    {
        if (rhs.Hash_key() == (*item).Hash_key())
        {
            hash[hash_key % size].erase(item);
            used --;
            return;
        }
        else 
        {  
            item ++;
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
std::vector<Hash_node_pseudo<T>> Hash_map<T>::Hash_map_all()
{
    std::vector<Hash_node_pseudo<T>> vec; 
    
    for (auto item : hash)
    {
        for (auto iterr : item)
        {
            vec.push_back( iterr );
        }
    }

    if (rehashhidx != -1)
    {
        for (auto item : rehash)
        {
            for (auto iterr : item)
            {
                vec.push_back(iterr);
            }
        }
    }

    return vec;
}

template <typename T>
int Hash_map<T>::Hash_map_size()
{
    return used + reused;
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
