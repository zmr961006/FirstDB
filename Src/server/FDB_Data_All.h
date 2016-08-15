/*************************************************************************
	> File Name: FDB_Data_All.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 20时39分04秒
 ************************************************************************/

#ifndef _FDB_DATA_ALL_H
#define _FDB_DATA_ALL_H

#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include"./FDB_Data_Base.h"
#include"./FDB_Key_val.h"
#define DB_DEFAULT 16

class Data_All
{
private:
    typedef char* (Data_All::*fun)(char*,char*, char*);
    int max_num;
    std::vector<Data_Base> DB;
    
    bool Data_All_add(std::string key_name, void *obj, int type_data, int db_num = 0);
    bool Data_All_val_del(std::string key_name, void *obj, int type_data, int db_num = 0);
    bool Data_All_del(std::string key_name, int db_num = 0);
    bool Data_All_value(std::string key_name, void *buff, int type_data, int db_num = 0);

    bool Add(char *key, char *val_key, int type_data, char *val_value, int db_num = 0);
    bool Add(char *key, char *val_key, int type_data, int db_num = 0);
    bool Val_Del(char *key, int type_data, char *val_key = " ", int db_num = 0);
    bool Del(const char *key, int db_num = 0);
    const char* Value(const char *key, int type_data, int db_num = 0);
    bool Find(const char *key, int db_num = 0);
    
    void Data_show();
    void Data_All_destory(int num = 0);
    void Data_All_destory();
    
    bool Data_All_add_time(std::string rhs, long long time, int db_num = 0);
    bool Data_All_add_ptime(std::string rhs, long long time, int db_num = 0);
    bool Data_All_set_time(std::string rhs, long long time, int db_num = 0);
    bool Data_All_set_ptime(std::string rhs,long long time, int db_num = 0);
    long long int Data_All_get_time(std::string rhs, int db_num = 0);

    void Data_All_show(int db_num = 0);
    int Data_All_get_num();

    char* HSET(char* key, char* val_key, char* val_value);
    char* HDEL(char* key, char* val_key, char* val_value);
    char* HGETALL(char* key, char* val_key, char* val_value);
    char* DEL(char* key, char* val_key, char* val_value);
    char* SET(char* key, char* val_key, char* val_value);
    char* GET(char* key, char* val_key, char* val_value);
    char* LSET(char* key, char* val_key, char* val_value);
    char* LGET(char* key, char* val_key, char* val_value);
    char* LPUSH(char* key, char* val_key, char* val_value);
    char* LPOP(char* key, char* val_key, char* val_value);
    char* RPUSH(char* key, char* val_key, char* val_value);
    char* RPOP(char* key, char* val_key, char* val_value);
public:
    Data_All(int num, int hash_def, int rehash_def);
    ~Data_All() = default;
    
    char *handle(std::string signal, std::string key, std::string val_key, std::string val_value);
};

#endif
