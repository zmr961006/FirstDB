/*************************************************************************
	> File Name: FDB_Data_All.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月26日 星期二 13时36分04秒
 ************************************************************************/

#include"./FDB_Data_All.h"
using namespace std;

Data_All::Data_All(int num, int hash_def, int rehash_def)
{
    db_num = 0;
    for (int i = 0; i < num; i++)
    {
        DB.push_back(Data_Base (hash_def, rehash_def));
    }
}

void Data_All::Data_show()
{
    for ( auto item : DB )
    {
        item.Data_Base_show();
    }
}

void Data_All::Data_All_destory(int num)
{
    DB[num].Data_Base_destory();
cout << num << endl;
}

void Data_All::Data_All_destory()
{
    for (auto item = DB.begin(); item != DB.end(); item++)
    {
        (*item).Data_Base_destory();
    }
}

bool Data_All::Data_All_add(std::string key_name, void *obj, int type_data)
{
    if (DB[db_num].Data_Base_find(key_name) == true) {
        if (DB[db_num].Data_Base_type_compare(key_name, type_data) == false) {
            return false;
        } else {
            DB[db_num].Data_Base_value_add(key_name, obj);
        }
    } else {
        Key_val ky(key_name, type_data, db_num);
        DB[db_num].Data_Base_add(ky);
        DB[db_num].Data_Base_value_add(key_name, obj);
    }
    return true;
}

bool Data_All::Data_All_val_del(std::string key_name, int type_data, void *obj)
{
    if (DB[db_num].Data_Base_type_compare(key_name, type_data) == true) {
        DB[db_num].Data_Base_value_del(key_name, obj);
        return true;
    }

    return false;
}

bool Data_All::Data_All_del(std::string key_name, int type_data)
{
    if (DB[db_num].Data_Base_type_compare(key_name, type_data) == true) {
        DB[db_num].Data_Base_del(key_name);
        return true;
    }

    return false;
}
            
bool Data_All::Data_All_value(std::string key_name, int type_data, void *buff)
{
    if (DB[db_num].Data_Base_type_compare(key_name, type_data) == true) {
        DB[db_num].Data_Base_value_value(key_name, buff);
        return true;
    }

    return false;
}
                 
bool Data_All::Data_All_add_time(std::string rhs, long long time)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_add_time(rhs, time);
        return true;
    }

    return false;
}

bool Data_All::Data_All_add_ptime(std::string rhs, long long time)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_add_ptime(rhs, time);
        return true;
    }

    return false;
}

bool Data_All::Data_All_set_time(std::string rhs, long long time)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_set_time(rhs, time);
        return true;
    }

    return false;
}

bool Data_All::Data_All_set_ptime(std::string rhs,long long time)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_set_ptime(rhs, time);
        return true;
    }

    return false;
}

long long int Data_All::Data_All_get_time(std::string rhs)
{
    return DB[db_num].Data_Base_get_time(rhs); 
}

void Data_All::Data_All_show()
{
    DB[db_num].Data_Base_show();
}

int Data_All::Data_All_get_num()
{
    return db_num;
}

void Data_All::Data_All_set_num(int num)
{
    db_num = num;
}
