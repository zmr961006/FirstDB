/*************************************************************************
	> File Name: FDB_Data_Base.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 20时36分38秒
 ************************************************************************/

#ifndef _FDB_DATA_BASE_H
#define _FDB_DATA_BASE_H

#include<iostream>
#include<list>
#include<vector>
#include"./FDB_Key_val.h"

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
    void Data_Base_update(Key_val rhs);
    void Data_Base_destory();			//删除整个hash表
    bool Data_Base_find(std::string);
    bool Data_Base_type_compare(std::string rhs, int type);
    unsigned int Data_Base_size();

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
    bool Data_Base_value_add(std::string rhs, void *obj);
    bool Data_Base_value_del(std::string rhs, void *obj);
    bool Data_Base_value_value(std::string rhs, void *buff);  
    bool Data_Base_value_destory(std::string rhs); 		//删除某个键值对

    unsigned int Data_Base_value_size(std::string rhs);
    bool Data_Base_add_time(std::string rhs, long long time);
    bool Data_Base_add_ptime(std::string rhs, long long time);
    bool Data_Base_set_time(std::string rhs, long long time);
    bool Data_Base_set_ptime(std::string rhs,long long time);
    long long int Data_Base_get_time(std::string rhs);

    char* FDB_Base_c_str(char *a, std::string rhs);
    void Data_Base_show();

    unsigned int GetKey_char(const void *key);
    unsigned int GetKey_int(unsigned int key);
};

#endif
