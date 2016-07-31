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
#include"./FDB_ziplist.h"
#include"./FDB_Stack.h"
#include"./FDB_Queue.h"
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
//int flag = 0;
    Key_val() = default;
    Key_val(std::string key_name, int type_data, int elem);
    Key_val(const Key_val &a);
    ~Key_val();
    void Key_val_add(void *obj);
    bool Key_val_del(void *obj);
    void Key_val_value(void *buff);
    void Key_val_destory();
    void Key_val_flag();
    int Key_val_size();
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
