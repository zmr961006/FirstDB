/*************************************************************************
	> File Name: FDB_Data_Base.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月26日 星期二 13时09分48秒
 ************************************************************************/

#ifndef FDB_DATA_BASE_CPP
#define FDB_DATA_BASE_CPP

#include"./FDB_Data_Base.h"
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
            Key_val a(*item);
            rehash[(*item).get_hash() % resize].push_front(a);
            hash[i].erase(item);
            reused++;
            rehashhidx++;
            used--;
            sum ++;
        }
        if ( (sum > rehash_default) || (used == 0))
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
        sum = 0;
        std::vector<std::list<Key_val>>().swap(rehash);
    }
}

void Data_Base::Data_Base_add(Key_val rhs)
{
    char *a = new char[rhs.get_key().size()+10];
    FDB_Base_c_str(a, rhs.get_key());
    unsigned int key = GetKey_char( a );
    rhs.set_hash_key(key);
    delete []a;
    
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
        if (resize == 0)
        {
            return ;
        }
        rehash[key%resize].push_front(rhs);
        reused++;
        
        Data_Base_rehash();
    }
    else 
    {
        hash[key%size].push_front(rhs);
        used++;
    } 
}


bool Data_Base::Data_Base_del(std::string rhs)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int hash_key = GetKey_char( a );
    delete []a;
    //若hash表大小是使用量的十倍则用rehash表进行对hash表减少空间的操作
    if ( (used != 0) && (size/used >= 10) && (rehashhidx == -1) )
    {
        rehashhidx = 0;
        resize = size / 2;
        reused = 0;
        std::vector<std::list<Key_val>> vec_rehash(resize);
        rehash = vec_rehash;
    }

    //在rehash表中进行delete操作
    if (rehashhidx != -1)
    {
        auto item = rehash[hash_key % resize].begin();
        while(item != rehash[hash_key % resize].end())
        {
            if (rhs == (*item).get_key())
            {
                hash[hash_key % resize].erase(item);
                reused--;
                Data_Base_rehash();
                return true;
            }
            else
            {
                item++;
            }
        }
        Data_Base_rehash();
    }

    //在hash表中进行delete操作
    auto item = hash[hash_key % size].begin();
    while(item != hash[hash_key % size].end())
    {
       if ( rhs == (*item).get_key() )
        {
            hash[hash_key % size].erase(item);
            used --;
            return true;
        }
        else 
        {  
            item ++;
        }
    }   
}

void Data_Base::Data_Base_update(Key_val rhs)
{
    Data_Base_del(rhs.get_key());
    Data_Base_add(rhs);
}

void Data_Base::Data_Base_destory()
{
    //用swap的方法对vector容器进行销毁工作（因为clear函数无法减少容器进行的预分配）
    std::vector<std::list<Key_val>>().swap(hash);
    std::vector<std::list<Key_val>>().swap(rehash);

    //重新对hash表进行初始化
    std::vector<std::list<Key_val>> vec(HASH_MIN);

    used = 0;
    size = HASH_MIN;
    hash = vec;
    resize = 0;
    reused = 0;
    rehashhidx = -1;
}


bool Data_Base::Data_Base_find(std::string rhs)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item : hash[key % size])
    {
        if (rhs == item.get_key())
        {
            return true;
        }
    }
    
    if (rehashhidx != -1)
    {
        for (auto item : rehash[key % resize])
        {
            if (rhs == item.get_key())
            {
                return true;
            }
        }
    }

    return false;
}

bool Data_Base::Data_Base_type_compare(std::string rhs, int type)
{    
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item : hash[key % size])
    {
        if (rhs == item.get_key())
        {
            if (type == item.get_type()) 
            {
                return true;
            }
            return false;
        }
    }
    
    if (rehashhidx != -1)
    {
        for (auto item : rehash[key % resize])
        {
            if (rhs == item.get_key())
            {
                if (type == item.get_type()) 
                {
                    return true;
                }
                return false;
            }
        }
    }

    return false;
}

unsigned int Data_Base::Data_Base_size()
{
    return used + reused;
}

bool Data_Base::Data_Base_value_add(std::string rhs, void *obj)
{    
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++) //gouzaole
    {
        if (rhs == (*item).get_key())
        {
            (*item).Key_val_add(obj);
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).Key_val_add(obj);
                return true;
            }
        }
    }

    return false;
}

bool Data_Base::Data_Base_value_del(std::string rhs, void *obj)
{       
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            if ((*item).Key_val_del(obj) == false)
            {
                return false;
            }
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                if ((*item).Key_val_del(obj) == false)
                {
                    return false;
                }
                return true;
            }
        }
    }
    
    return false;
}

bool Data_Base::Data_Base_value_value(std::string rhs, void *buff)
{ 
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            (*item).Key_val_value(buff);
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).Key_val_value(buff);
                return true;
            }
        }
    }

    return false;
}

bool Data_Base::Data_Base_value_destory(std::string rhs)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            (*item).Key_val_destory();
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).Key_val_destory();
                return true;
            }
        }
    }

    return false;
}

unsigned int Data_Base::Data_Base_value_size(std::string rhs)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            return (*item).Key_val_size();
        }
    }

    if (rehashhidx != -1)
    {
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                return (*item).Key_val_size();
            }
         }
    }
}

bool Data_Base::Data_Base_add_time(std::string rhs, long long time)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            (*item).add_cut_time(time);
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).add_cut_time(time);
                return true;
            }
        }
    }

    return false;
}

bool Data_Base::Data_Base_add_ptime(std::string rhs, long long time)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            (*item).add_cut_ptime(time);
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).add_cut_ptime(time);
                return true;
            }
        }
    }

    return false;
}

bool Data_Base::Data_Base_set_time(std::string rhs, long long time)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            (*item).set_cut_time(time);
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).set_cut_time(time);
                return true;
            }
        }
    }

    return false;
}

bool Data_Base::Data_Base_set_ptime(std::string rhs,long long time)
{    
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            (*item).set_cut_ptime(time);
            return true;
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                (*item).set_cut_ptime(time);
                return true;
            }
        }
    }

    return false;
}

long long Data_Base::Data_Base_get_time(std::string rhs)
{
    char *a = new char[rhs.size()+10];
    FDB_Base_c_str(a, rhs);
    unsigned int key = GetKey_char( a );
    delete []a;

    for (auto item = hash[key % size].begin(); item != hash[key % size].end(); item++)
    {
        if (rhs == (*item).get_key())
        {
            return (*item).get_cut_time();
        }
    }

    if (rehashhidx != -1)
    {
        Data_Base_rehash();
        for (auto item = rehash[key % resize].begin(); item != rehash[key % resize].end(); item++)
        {
            if (rhs == (*item).get_key())
            {
                return (*item).get_cut_time();
            }
        }
    }
}

char* Data_Base::FDB_Base_c_str(char *a, std::string rhs)
{
    strcpy(a, rhs.c_str());
    for (int i = rhs.size(); i < rhs.size()+10; i++)
    {
         a[i] = 0;
    }
    return a;
}

void Data_Base::Data_Base_show()
{
    std::cout << "hash: " << std::endl;
    std::cout << "size: " << size << " used: " << used << " hash_size: " << hash.size() << std::endl;
    int i = 0;
    for (auto item : hash)
    {
        //std::cout << item.size() << std::endl; 
        for (auto it : item)
        {
            std::cout << i << " : " << std::endl;
            std::cout << it.get_key() << "---" << it.get_hash() << std::endl;
        }
        i++;
    }

    std::cout << "rehash: " << std::endl;
    std::cout << "resize: " << size << " reused: " << reused << " rehash_size: " <<  rehash.size() << std::endl;
    i = 0;
    for (auto item : rehash)
    {
        for (auto it : item)
        {
            std::cout << i << " : " << endl;
            std::cout << it.get_key() << "---" << it.get_hash() << std::endl;
        }
        i++;
    }
    std::cout << "rehashhidx: " << rehashhidx << std::endl;
    std::cout << "rehash_default: " << rehash_default << std::endl;
    std::cout << "-----------------------------" << std::endl;
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

#endif
