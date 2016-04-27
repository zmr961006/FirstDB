/*************************************************************************
	> File Name: FDB_Key_val.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 17时34分24秒
 ************************************************************************/

#ifndef _FDB_KEY_VAL_H
#define _FDB_KEY_VAL_H

#include<iostream>
#include<string>
#include"./FDB_Data_num.h"
#include"./FDB_Hash_map.h"
#include"./FDB_String.h"
#include"./FDB_String.cpp"
#include<sys/time.h>

#define TIMR_DONE -1

class Key_val
{
private:
    std::string key;
    void *value;
    int type;
    unsigned int hash_key;
    long long  cut_time;
    int Server_ID;
public:
    Key_val() = default;
    Key_val(std::string key_name, void *obj, unsigned int hash, int type_data, int elem);
    ~Key_val() = default;
    void Key_val_add(char * key_a, std::string value_b);
    void add_cut_time(long long time);
    void add_cut_ptime(long long time);
    void set_cut_time(long long time);
    void set_cut_ptime(long long time);
    void set_hash_key(unsigned int hash);
    int get_type();
    unsigned int get_hash();
    std::string get_key();
    long long get_cut_time();
};

#endif
