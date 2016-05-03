/*************************************************************************
	> File Name: FDB_Data_Base.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月26日 星期二 13时09分48秒
 ************************************************************************/

#include<iostream>
using namespace std;

Data_Base::Data_Base(int hash_def, int rehash_def)
{
    std::vector<std::list<Key_val>> vec(hash_def);

    used = 0;
    size = hash_def;
    hash = vec;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
    rehash_default = rehash_def;
}


void Data_Base::Data_Base_rehash()
{
    int i = 0;
    int sum = 0;
    //实现了键值对从hash向rehash的迁移
    while (1)
    {
        while (hash[i].size() != 0)
        {
            auto item = hash[i].begin();
            rehash[(*item).get_key() % resize].push_front(*item);
            hash[i].erase(item);
            reused++;
            rehashhidx++;
            used--;
        }
        if ( (++sum > rehash_default) || (rehashhidx == size))
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
        std::vector<std::list<Key_val>>().swap(rehash);
    }
}

void Data_Base::Data_Base_add(Key_val rhs)
{
    if (Hash_map_find(rhs) == true)
    {
        Hash_map_change(rhs);
        return ;
    }

    unsigned int key = rhs.get_key();
    rhs.set_hash_key(key);
    
    //当hash表的用量大于hash表大小的时候，启用rehash
    if ((rehashhidx == -1) && (used/size >= 1))
    {
        rehashhidx = 0;
        resize = size * 2;
        reused = 0;
        std::vector<std::list<Key_val>> vec_rehash(resize);
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


bool Data_Base::Data_Base_del(std::string rhs)
{
    if (Hash_map_find(rhs) == false)
    {
        return false;
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


unsigned int Data_Base::GetKey_int(unsigned int key){
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3 );
    key ^=  (key >> 6 );
    key += ~(key << 11);
    key ^=  (key >> 16);
    return key;
}

unsigned int Data_Base::GetKey_char(const void *key){
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

