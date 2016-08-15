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

bool Data_All::Data_All_del(std::string key_name, int db_num)
{
    if (Find(key_name.c_str()) == true) {
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

bool Data_All::Del(const char *key, int db_num)
{
	std::string key_all(key);
	if (Data_All_del(key_all, db_num) == false)
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
		std::string str("");
		if (Data_All_value(key_all, buff, type_data, db_num) == false)
		{
			delete (std::vector<Hash_node_pseudo<std::string>> *) buff;
			return "nil";
		}
		
		for (auto item : (*(std::vector<Hash_node_pseudo<std::string>> *)buff))
		{
			str += "\"";
			str += item.Hash_key().StringGetChar();
			str += "   ";
			str += item.Hash_value();
			str += "\n";
			str += "\"";
		}
		
		return str.c_str();
	} else if (type_data == Ziplist_NUM) {
		void *buff = new std::vector<std::string>;
		std::string str("");
		std::string  key_all(key);
		if (Data_All_value(key_all, buff, type_data, db_num) == false) {
			
			delete (std::vector<std::string> *)buff;
			return "nil";
		}
		
		for (auto item : (*(std::vector<std::string>*) buff))
		{
			str += "\"";
			str += item;
			str += "\n";
			str += "\"";
		}
		delete (std::vector<std::string> *)buff;
		return str.c_str();
	} else if (type_data == String_NUM) {
		void *buff = new String;
		std::string  key_all(key);
		if (Data_All_value(key_all, buff, type_data, db_num) == false)
		{
			delete (String *) buff;
			return "nil";
		}
		string ch = (*(String *)buff).StringGetChar();
		ch = "\"" + ch + "\"";
		delete (String *) buff;
		return ch.c_str();
	} else if (type_data == Stack_NUM || (type_data == Queue_NUM)) {
		void *buff = new std::string;
		std::string  key_all(key);
		if (Data_All_value(key_all, buff, type_data, db_num) == false)
		{
			delete (std::string *)buff;
			return "nil";
		}
		string str = (*(std::string *)buff);
		str = "\"" + str + "\"";
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

char* Data_All::HSET(char* key, char* val_key, char* val_value)
{
	char *a;
	if (Add(key, val_key, 1, val_value) == false ) {
		a = "hset error";
	} else {
		a = "OK";
	}

	return a;
}

char* Data_All::HDEL(char* key, char* val_key, char* val_value)
{
	char *a;
	if (Val_Del(key, 1, val_key) == false ) {
		a = "nil";
	} else {
		a = "OK";
	}
	
	return a;
}

char* Data_All::HGETALL(char* key, char* val_key, char* val_value)
{
	const char *a;
	a = Value(key, 1);
	
	char* b = new char[strlen(a)+1];
	strcpy(b,a);
	return b;
}

char* Data_All::DEL(char* key, char* val_key, char* val_value)
{
	char *a;
	if (Del(key)) {
		a = "nil";
	} else {
		a = "OK";
	}

	return a;
}

char* Data_All::SET(char* key, char* val_key, char* val_value)
{
	char *a;
	if (Add(key, val_key, 3) == false ) {
	    a = "set error";
	} else {
		a = "OK";
	}

	return a;
}

char* Data_All::GET(char* key, char* val_key, char* val_value)
{
	const char *a;
	a = Value(key, 3);

	char* b = new char[strlen(a)+1];
	strcpy(b, a);
	return b;
}

char* Data_All::LSET(char* key, char* val_key, char* val_value)
{
    char *a;
	if (Add(key, val_key, 2) == false ) {
		a = "lset error";
	} else {
		a = "OK";
	}

	return a;
}

char* Data_All::LGET(char* key, char* val_key, char* val_value)
{
	const char *a;
	a = Value(key, 2);

	char* b = new char[strlen(a)+1];
	strcpy(b,a);
	return b;
}

char* Data_All::LPUSH(char* key, char* val_key, char* val_value)
{
	char *a;
	if (Add(key, val_key, 4) == false ) {
		a = "lpush error";
	} else {
		a = "OK";
	}

	return a;
}

char* Data_All::LPOP(char* key, char* val_key, char* val_value)
{
	const char *a;
	a = Value(key, 4);

	char* b = new char[strlen(a)+1];
	strcpy(b,a);
	return b;
}

char* Data_All::RPUSH(char* key, char* val_key, char* val_value)
{
	char *a;
	if (Add(key, val_key, 5) == false ) {
		a = "rpush error";
	} else {
		a = "OK";
	}

	return a;
}

char* Data_All::RPOP(char* key, char* val_key, char* val_value)
{
	const char *a;
	a = Value(key, 5);

	char* b = new char[strlen(a)+1];
	strcpy(b,a);
	return b;
}

char* Data_All::handle(string signal, string key, string val_key, string val_value)
{
	char *ret;
	// map<char *, fun> mp;
	// mp.insert(pair<char *, fun> ("HSET" ,&Data_All::HSET));
	// mp.insert(pair<char *, fun> ("HDEL",&Data_All::HDEL));
	// mp.insert(pair<char *, fun> ("HGETALL",&Data_All::HGETALL));
	// mp.insert(pair<char *, fun> ("DEL",&Data_All::DEL));
	// mp.insert(pair<char *, fun> ("SET",&Data_All::SET));
	// mp.insert(pair<char *, fun> ("GET",&Data_All::GET));
	// mp.insert(pair<char *, fun> ("LSET",&Data_All::LSET));
	// mp.insert(pair<char *, fun> ("LGET",&Data_All::LGET));
	// mp.insert(pair<char *, fun> ("LPUSH",&Data_All::LPUSH));
	// mp.insert(pair<char *, fun> ("LPOP",&Data_All::LPOP));
	// mp.insert(pair<char *, fun> ("RPUSH", &Data_All::RPUSH));
	// mp.insert(pair<char *, fun> ("RPOP",&Data_All::RPOP));

	map<string, fun> mp;
	mp.insert(pair<string, fun> ("HSET" ,&Data_All::HSET));
	mp.insert(pair<string, fun> ("HDEL",&Data_All::HDEL));
	mp.insert(pair<string, fun> ("HGETALL",&Data_All::HGETALL));
	mp.insert(pair<string, fun> ("DEL",&Data_All::DEL));
	mp.insert(pair<string, fun> ("SET",&Data_All::SET));
	mp.insert(pair<string, fun> ("GET",&Data_All::GET));
	mp.insert(pair<string, fun> ("LSET",&Data_All::LSET));
	mp.insert(pair<string, fun> ("LGET",&Data_All::LGET));
	mp.insert(pair<string, fun> ("LPUSH",&Data_All::LPUSH));
	mp.insert(pair<string, fun> ("LPOP",&Data_All::LPOP));
	mp.insert(pair<string, fun> ("RPUSH", &Data_All::RPUSH));
	mp.insert(pair<string, fun> ("RPOP",&Data_All::RPOP));

    //char *csignal = new char[signal.size()+1];
    //char *ckey = new char[key.size()+1];
    //char *cval_key = new char[val_key.size()+1];
    //char *cval_value = new char[val_value.size()+1];

    //csignal = (char *)signal.c_str();
    //ckey = (char*)key.c_str();
    //cval_key = (char*)val_key.c_str();
    //cval_value = (char*)val_value.c_str();

	ret = (this->*mp[signal])((char*)key.c_str(), (char*)val_key.c_str(), (char*)val_value.c_str());

    //delete csignal;
    //delete ckey;
    //delete cval_key;
    //delete cval_value;

	return ret;
}
