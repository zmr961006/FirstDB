/*************************************************************************
	> File Name: FDB_judge_commd.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年08月13日 星期六 12时24分14秒
 ************************************************************************/

#include"FDB_judge_commd.h"

std::string judge_commd::judge_commd_func(char* str, int num)
{
    bool n;        /*判断str是不是合法命令*/
    std::string a; /*返回的提示字符串*/

    if( (n = strcmp("hgetall",str) && strcmp("HGETALL", str) && strcmp("get", str) && strcmp("GET", str) && strcmp("lget", str) && strcmp("LGET", str) ) == 0 ){
        if(num != 2){
            return (a = "(error) ERR wrong number of arguments for command");
        }

        return ( a  = "ok");
    }

    if( (n = strcmp("hdel", str) && strcmp("HDEL", str) && strcmp("set", str) && strcmp("SET", str) && strcmp("lset", str) && strcmp("LSET", str) && strcmp("lpush",str) && strcmp("LPUSH", str) ) == 0){
        if(num != 3){
            return (a = "(error) ERR wrong number of arguments for command");
        }
        return (a = "ok");
    }

    if( ( n = strcmp("hset", str) && strcmp("HSET", str) && strcmp("lpop", str) && strcmp("LPOP", str) && strcmp("del",str) && strcmp("DEL", str) && strcmp("rpush", str) && strcmp("RPUSH", str) && strcmp("rpop", str) && strcmp("RPOP", str) ) == 0 ){
        if(num != 4){
            return (a = "(error) ERR wrong number of arguments for command");
        }
        return (a = "ok");
    }

    return (a = "(error) ERR unknown command");

}


