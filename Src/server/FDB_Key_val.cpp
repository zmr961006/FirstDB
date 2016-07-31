/*************************************************************************
	> File Name: FDB_Key_val.cpp
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 21时59分20秒
 ************************************************************************/

#include"./FDB_Key_val.h"

using namespace std;

Key_val::Key_val(std::string key_name, int type_data, int elem)
{
    key = key_name;
    type  = type_data;
    hash_key = 0;
    cut_time = -1;
    Server_ID = elem;

    /*obj*/
    if (type_data == Hash_Map_pseudo_NUM)
    {
        value = new Hash_map_pseudo<std::string>;
    }
    else if (type_data == Hash_Map_NUM)
    {
        value = new Hash_map<std::string> ;
    }
    else if (type_data == Ziplist_NUM)
    {
        value = new Ziplist<std::string>;
    }
    else if (type_data == String_NUM)
    {
        value = new String;
    }
    else if (type_data == Stack_NUM)
    {
        value = new FDB_Stack<std::string>;
    }
    else if (type_data == Queue_NUM)
    {
        value = new FDB_Queue<std::string>;
    }
    /*obj*/
}

Key_val::Key_val(const Key_val &a)
{
    key = a.key;
    type  = a.type;
    hash_key = a.hash_key;
    cut_time = a.cut_time;
    Server_ID = a.Server_ID;
    /*obj*/
    if (type == Hash_Map_pseudo_NUM)
    {
        value = new Hash_map_pseudo<std::string>;
 (*(Hash_map_pseudo<std::string> *)value) = (*(Hash_map_pseudo<std::string> *)a.value);
    }
    else if (type == Hash_Map_NUM)
    {
        value = new Hash_map<std::string> ;
(*(Hash_map<std::string> *)value) = (*(Hash_map<std::string> *)a.value);
    }
    else if (type == Ziplist_NUM)
    {
        value = new Ziplist<std::string>;
(*(Ziplist<std::string> *)value) = (*(Ziplist<std::string> *)a.value);
    }
    else if (type == String_NUM)
    {
        value = new String;
        (*(String *)value) = (*(String *)a.value);
    }
    else if (type == Stack_NUM)
    {
        value = new FDB_Stack<std::string>;
(*(FDB_Stack<std::string> *)value) = (*(FDB_Stack<std::string> *)a.value);
    }
    else if (type == Queue_NUM)
    {
        value = new FDB_Queue<std::string>;
(*(FDB_Queue<std::string> *)value) = (*(FDB_Queue<std::string> *)a.value);
    }
    /*obj*/
}


Key_val::~Key_val()
{
        if (type == Hash_Map_pseudo_NUM)
        {
            delete (Hash_map_pseudo<std::string> *) value;
        }
        else if (type == Hash_Map_NUM)
        {
            delete (Hash_map<std::string> *)value;
        }
        else if (type == Ziplist_NUM)
        {
            delete (Ziplist<std::string> *)value;
        }
        else if (type == String_NUM)
        {
            delete (String *)value;
        }
        else if (type == Stack_NUM)
        {
            delete (FDB_Stack<std::string>*)value;
        }
        else if (type == Queue_NUM)
        {
            delete (FDB_Queue<std::string>*)value;
        }
}

void Key_val::Key_val_add(void *obj)
{
    if (type == Hash_Map_pseudo_NUM)
    {
        (*(Hash_map_pseudo<std::string>*)value).Hash_pseudo_set(*(Hash_node_pseudo<std::string>*)obj);
        if (Key_val_size() == (HASH_DEFAULT / 2))
        {
            Hash_map_pseudo<std::string> hash_pseudo; 
            hash_pseudo = (*(Hash_map_pseudo<std::string>*)value);
            type = Hash_Map_NUM;
            delete (Hash_map_pseudo<std::string> *) value;
            value = new Hash_map<std::string>(hash_pseudo);
        }
    }
    else if (type == Hash_Map_NUM)
    {
        (*(Hash_map<string> *)value).Hash_map_add(*(Hash_node_pseudo<std::string>*)obj);
    }
    else if (type == Ziplist_NUM)
    {
        (*(Ziplist<std::string> *)value).Ziplist_add(*(std::string *)obj);
    }
    else if (type == String_NUM)
    {
        (*(String *)value) = (*(String *)obj);
    }
    else if (type == Stack_NUM)
    {
        (*(FDB_Stack<std::string> *) value).FDB_Stack_push(*(std::string *)obj);
    }
    else if (type == Queue_NUM)
    {
        (*(FDB_Queue<std::string> *) value).FDB_Queue_push(*(std::string *)obj);
    }
}

bool Key_val::Key_val_del(void *obj)
{
    if (type == Hash_Map_pseudo_NUM)
    {
        if ( ((*(Hash_map_pseudo<string>*)value).
            Hash_pseudo_test((*(Hash_node_pseudo<string>*)obj).Hash_key() )) == false)
        {
            return false;
        }
        (*(Hash_map_pseudo<string> *)value).
            Hash_pseudo_del((*(Hash_node_pseudo<string>*)obj).Hash_key());
        return true;
    }
    else if (type == Hash_Map_NUM)
    {
        if ((*(Hash_map<std::string> *)value).Hash_map_find(*(Hash_node_pseudo<std::string>* )obj) == false)
        {
            return false;
        }
        (*(Hash_map<std::string> *)value).Hash_map_del(*(Hash_node_pseudo<std::string>*)obj);
        return true;
    }
    else if (type == Ziplist_NUM)
    {
        if ( (*(Ziplist<std::string>*)value).Ziplist_find(*(std::string *)obj) == false)
        {
            return false;
        }
        (*(Ziplist<std::string>*)value).Ziplist_del(*(std::string *)obj);
        return true;
    }
    else if (type == Stack_NUM)
    {
        if ( (*(FDB_Stack<std::string> *)value).FDB_Stack_empty() == true )
        {
            return false;
        }
        (*(FDB_Stack<std::string> *)value).FDB_Stack_pop();
        return true;
    }
    else if (type == Queue_NUM)
    {
        if ( (*(FDB_Queue<std::string> *)value).FDB_Queue_empty() == true )
        {
            return false;
        }
        (*(FDB_Queue<std::string> *)value).FDB_Queue_pop();
        return true;
    }
}

void Key_val::Key_val_value(void *buff)
{
    if (type == Hash_Map_pseudo_NUM)
    {
        (*(std::vector<Hash_node_pseudo<std::string>>*)buff) = 
            (*(Hash_map_pseudo<std::string>*)value).Hash_pseudo_data();
    }
    else if (type == Hash_Map_NUM)
    {
        (*(std::vector<Hash_node_pseudo<std::string>> *)buff) = 
            (*(Hash_map<std::string>*)value).Hash_map_all();
    }
    else if (type == Ziplist_NUM)
    {
        (*(std::vector<std::string>*)buff) = 
            (*(Ziplist<std::string>*)value).Ziplist_return();
    }
    else if (type == String_NUM)
    {
        (*(String *)buff) = (*(String *)value);
    }
    else if (type == Stack_NUM)
    {
        (*(string *)buff) =
            (*(FDB_Stack<std::string> *)value).FDB_Stack_top();
    }
    else if (type == Queue_NUM)
    {
        (*(string *)buff) =
            (*(FDB_Queue<std::string> *)value).FDB_Queue_front();
    }
}

void Key_val::Key_val_destory()
{
    if(type == Hash_Map_pseudo_NUM)
    {
        (*(Hash_map_pseudo<std::string>*)value).Hash_pseudo_destory();
    }
    else if (type == Hash_Map_NUM)
    {
        (*(Hash_map<std::string> *)value).Hash_map_destory();
    }
    else if (type == Ziplist_NUM)
    {
        (*(Ziplist<std::string>*)value).Ziplist_destory();
    }
    else if (type == Stack_NUM)
    {
        (*(FDB_Stack<std::string> *)value).FDB_Stack_destory();
    }
    else if (type == Queue_NUM)
    {
        (*(FDB_Queue<std::string> *)value).FDB_Queue_destory();
    }
}

int Key_val::Key_val_size()
{
    if (type == Hash_Map_pseudo_NUM)
    {
        return (*(Hash_map_pseudo<std::string>*)value).Hash_pseudo_size();
    }
    else if (type == Hash_Map_NUM)
    {
        return (*(Hash_map<std::string> *)value).Hash_map_size();
    }
    else if (type == Ziplist_NUM)
    {
        return (*(Ziplist<std::string> *)value).Ziplist_size();
    }
    else if (type == Stack_NUM)
    {
        return (*(FDB_Stack<std::string> *)value).FDB_Stack_size();
    }
    else if (type == Queue_NUM)
    {
        return (*(FDB_Queue<std::string> *)value).FDB_Queue_size();
    }
}

void Key_val::add_cut_time(long long time)
{
    add_cut_ptime(1000 * time);
}

void Key_val::add_cut_ptime(long long time)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    time += (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    set_cut_ptime(time);
}

void Key_val::set_cut_time(long long time)
{
    set_cut_ptime(time * 1000);
}

void Key_val::set_cut_ptime(long long time)
{
    cut_time = time;
}

void Key_val::set_hash_key(unsigned int hash)
{
    hash_key = hash;
}

int Key_val::get_type()
{
    return type;
}

unsigned int Key_val::get_hash()
{
    return hash_key;
}

std::string Key_val::get_key()
{
    return key;
}

long long Key_val::get_cut_time()
{
    return cut_time;
}
