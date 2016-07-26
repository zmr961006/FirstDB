/*************************************************************************
	> File Name: FDB_Data_All.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月25日 星期一 20时39分04秒
 ************************************************************************/

#ifndef _FDB_DATA_ALL_H
#define _FDB_DATA_ALL_H

#define DB_DEFAULT 16

class Data_All
{
private:
    int db_num;
    Data_Base *DB;
public:
    Data_All():db_num(DB_DEFAULT), DB(new Data_Base[DB_DEFAULT]) {  }
    Data_All(int num):db_num(num), DB(new Data_Base[num]) {  }
    ~Data_Base();
};

#endif
