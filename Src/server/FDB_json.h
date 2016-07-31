/*************************************************************************
	> File Name: FDB_json.h
	> Author: 
	> Mail: 
	> Created Time: 2016年05月04日 星期三 10时11分33秒
 ************************************************************************/

#ifndef _FDB_JSON_H
#define _FDB_JSON_H

#include<iostream>
#include<string>
#include"../jsoncpp-src-0.5.0/include/json/json.h"


class JSon{

    private:
        
        std::string message;
        Json::Value json_obj;
        /*std::string key;             变量记录，预留未定
        std::string operation;
        std::string buf;
        int size;
        int type_data;
        int type_data2;*/
        int ack;

    public:
        
        JSon(std::string key,std::string operation,int type_data,int type_data2,std::string buf);
        JSon(std::string);
        int Json_get_size();
        int Json_get_typedata();
        int Json_get_typedata2();
        int Json_get_ack();
        std::string Json_get_key();
        std::string Json_get_operation();
        std::string Json_get_buf();


};




#endif
