/*************************************************************************
	> File Name: FDB_judge_commd.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年08月13日 星期六 12时23分28秒
 ************************************************************************/

#ifndef _FDB_JUDGE_COMMD_H
#define _FDB_JUDGE_COMMD_H

#include "FDB_jheader.h"

/*std::string commd_arry[MAXSTR];  定义一个全局变量，来存储所有的命令(在FDB_cli.h里面初始化)*/

class judge_commd
{
public:
    std::string judge_commd_func(char* str, int num);          /*判断命令是否合法*/
};
#endif
