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
    max_num = num;
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

void Data_All::Data_All_destory(int db_num)
{
    DB[db_num].Data_Base_destory();
}

void Data_All::Data_All_destory()
{
    for (auto item = DB.begin(); item != DB.end(); item++)
    {
        (*item).Data_Base_destory();
    }
}

/*------------------------------------------private--------------------------------------*/
bool Data_All::Data_All_add(std::string key_name, void *obj, int type_data, int db_num)
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

bool Data_All::Data_All_val_del(std::string key_name, void *obj, int type_data, int db_num)
{
    if (DB[db_num].Data_Base_type_compare(key_name, type_data) == true) {
        DB[db_num].Data_Base_value_del(key_name, obj);
        return true;
    }

    return false;
}

bool Data_All::Data_All_del(std::string key_name, int type_data, int db_num)
{
    if (DB[db_num].Data_Base_type_compare(key_name, type_data) == true) {
        DB[db_num].Data_Base_del(key_name);
        return true;
    }

    return false;
}
            
bool Data_All::Data_All_value(std::string key_name, void *buff, int type_data, int db_num)
{
    if (DB[db_num].Data_Base_type_compare(key_name, type_data) == true) {
        DB[db_num].Data_Base_value_value(key_name, buff);
        return true;
    }

    return false;
}

/*------------------------------------------private--------------------------------------*/


/*------------------------------------------public--------------------------------------*/

bool Data_All::Add(char *key, char *val_key, int type_data, char *val_value, int db_num)
{
    if ((type_data == Hash_Map_pseudo_NUM) || (type_data ==Hash_Map_NUM)) {
        void *obj = new Hash_node_pseudo<string>;
        std::string key_all(key);
        String Str_val_key(val_key);
        std::string str_val_value(val_value);
        Hash_node_pseudo<string> hmp(Str_val_key, str_val_value);
        (*(Hash_node_pseudo<string> *) obj) = hmp;

        if (Data_All_add(key_all, obj, type_data, db_num) == false)
        {
            delete (Hash_node_pseudo<string> *) obj;
            return false;
        }
        delete (Hash_node_pseudo<string> *) obj;
    }   
    return true;
}

bool Data_All::Add(char *key, char *val_key, int type_data, int db_num)
{ 
    if ((type_data == Ziplist_NUM) || (type_data == Stack_NUM) || (type_data == Queue_NUM)) {
        void *obj = new std::string;
        std::string key_all(key);
        std::string str_value(val_key);
        (*(std::string *)obj) = str_value;

        if (Data_All_add(key_all, obj, type_data, db_num) == false)
        {
            delete (std::string *)obj;
            return false;
        }
        delete (std::string *)obj;
    } else if (type_data == String_NUM) {
        void *obj = new String;
        std::string key_all(key);
        String Str_value(val_key);
        (*(String *)obj) = Str_value;

        if (Data_All_add(key_all, obj, type_data, db_num) == false)
        {
            delete (String *)obj;
            return false;
        }
        delete (String *)obj;
    } 

    return true;
}

bool Data_All::Val_Del(char *key, int type_data, char *val_key, int db_num)
{
    if ((type_data == Hash_Map_pseudo_NUM) || (type_data == Hash_Map_NUM)) {
        void *obj = new Hash_node_pseudo<string>;
        std::string key_all(key);
        String Str_val_key(val_key);
        Hash_node_pseudo<string> hmp(Str_val_key, " ");
        (*(Hash_node_pseudo<string> *) obj) = hmp;
        if (Data_All_val_del(key_all, obj, type_data, db_num) == false)
        {
            delete (Hash_node_pseudo<string> *) obj;
            return false;
        }
        delete (Hash_node_pseudo<string> *) obj;
    } else if ((type_data == Ziplist_NUM) ) {
        void *obj = new std::string;
        std::string key_all(key);
        std::string str_value(val_key);
        (*(std::string *)obj) = str_value;

        if (Data_All_val_del(key_all, obj, type_data, db_num) == false)
        {
            delete (std::string *)obj;
            return false;
        }
        delete (std::string *)obj;
    } else if ((type_data == Stack_NUM) || (type_data == Queue_NUM)) {
        void *obj;
        std::string key_all(key);
        
        if (Data_All_val_del(key_all, obj, type_data, db_num) == false)
        {
            return false;
        }
    }

    return true;
}

bool Data_All::Del(const char *key, int type_data, int db_num)
{
    std::string key_all(key);
    if (Data_All_del(key_all, type_data, db_num) == false)
    {
        return true;
    }
    return false;
    
}

const char* Data_All::Value(const char *key, int type_data, int db_num)
{
    if ((type_data == Hash_Map_pseudo_NUM) || (type_data == Hash_Map_NUM)) {
        void *buff = new std::vector<Hash_node_pseudo<std::string>>;
        std::string key_all(key);
        Data_All_value(key_all, buff, type_data, db_num);
        std::string str("");
        
        for (auto item : (*(std::vector<Hash_node_pseudo<std::string>> *)buff))
        {
            str += item.Hash_key().StringGetChar();
            str += "   ";
            str += item.Hash_value();
            str += "\n";
        }
        delete (std::vector<Hash_node_pseudo<std::string>> *) buff;
        return str.c_str();
    } else if (type_data == Ziplist_NUM) {
        void *buff = new std::vector<std::string>;
        std::string  key_all(key);
        Data_All_value(key_all, buff, type_data, db_num);
        std::string str("");
        for (auto item : (*(std::vector<std::string>*) buff))
        {
            str += item;
            str += "\n";
        }
        delete (std::vector<std::string> *)buff;
        return str.c_str();
    } else if (type_data == String_NUM) {
        void *buff = new String;
        std::string  key_all(key);
        Data_All_value(key_all, buff, type_data, db_num);
        string ch = (*(String *)buff).StringGetChar();
        delete (String *) buff;
        return ch.c_str();
    } else if (type_data == Stack_NUM) {
        void *buff = new std::string;
        std::string  key_all(key);
        Data_All_value(key_all, buff, type_data, db_num);
        string str = (*(std::string *)buff);
        delete (std::string *)buff;
        return str.c_str();
    }
}

bool Data_All::Find(const char *key, int db_num)
{
    string str(key);
    if (DB[db_num].Data_Base_find(str) == true)
    {
        return true;
    }

    return false;
}

/*------------------------------------------public--------------------------------------*/
                 
bool Data_All::Data_All_add_time(std::string rhs, long long time, int db_num)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_add_time(rhs, time);
        return true;
    }

    return false;
}

bool Data_All::Data_All_add_ptime(std::string rhs, long long time, int db_num)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_add_ptime(rhs, time);
        return true;
    }

    return false;
}

bool Data_All::Data_All_set_time(std::string rhs, long long time, int db_num)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_set_time(rhs, time);
        return true;
    }

    return false;
}

bool Data_All::Data_All_set_ptime(std::string rhs,long long time, int db_num)
{
    if ( DB[db_num].Data_Base_find(rhs) == true ){
        DB[db_num].Data_Base_set_ptime(rhs, time);
        return true;
    }

    return false;
}

long long int Data_All::Data_All_get_time(std::string rhs, int db_num)
{
    return DB[db_num].Data_Base_get_time(rhs); 
}

void Data_All::Data_All_show(int db_num)
{
    DB[db_num].Data_Base_show();
}

int Data_All::Data_All_get_num()
{
    return max_num;
}