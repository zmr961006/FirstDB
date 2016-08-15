/*************************************************************************
	> File Name: FDB_json.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年08月09日 星期二 20时27分56秒
 ************************************************************************/

#ifndef _FDB_JSON_H
#define _FDB_JSON_H

#define MAXLINE 4096
#include<string.h>
#include"../jsoncpp-src-0.5.0/include/json/json.h"
//#include<json.h>
//#include<json/json.h>
//#include"FDB_jheader.h"

class fdb_json
{
public:

    std::string json_tostr(std::string buff);
    std::string str_tojson(int i, std::string buff[MAXLINE]);
    fdb_json(){
        jflag = 0;
    }

    std::string get_comm_name();
    std::string get_key();
    std::string get_value();
    std::string get_jadd();
    std::string get_num();

    void print_str();

private:

    int jflag;                                /*用于标记是否已经有json字符串转换，没有转换就不能调用一系列get函数*/
    Json::Reader reader;
    Json::Value root;
};

#endif
