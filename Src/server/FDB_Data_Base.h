/*************************************************************************
	> File Name: FDB_Data_Base.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 20时36分38秒
 ************************************************************************/

#ifndef _FDB_DATA_BASE_H
#define _FDB_DATA_BASE_H

class Data_Base
{
private:
    unsigned long used;
    unsigned long size;
    std::vector<std::list<Key_val>> hash;
    unsigned long reused;
    unsigned long resize;
    std::vector<std::list<Key_val>> rehash;
    int rehashhidx;
    int rehash_default;
public:
    /*hash_def是创建空hash表的大小，rehash_def为每次渐近式rehash转入的个数，均由配置文件读取*/
    Data_Base(int hash_def, int rehash_def);    //hash_def创建空哈希表的大小，由配置文件读取
    ~Data_Base() = default;
    void Data_Base_add(Key_val rhs);
    bool Data_Base_del(std::string rhs_key);
    void Data_Base_rehash();

    unsigned int GetKey_char(const void *key);
    unsigned int GetKey_int(unsigned int key);
};

#endif
