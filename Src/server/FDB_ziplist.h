/*************************************************************************
	> File Name: FDB_ziplist.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月10日 星期日 16时29分44秒
 ************************************************************************/

#ifndef _FDB_ZIPLIST_H
#define _FDB_ZIPLIST_H

#include<iostream>
#include<vector>

template <typename T>
class Ziplist
{
private:
    vector<T> data;
public:
    Ziplist() {  }
    Ziplist(vector<T> rhs);
    ~Ziplist() {  }
    void Ziplist_add(T rhs);
    void Ziplist_del(T rhs);
    void Ziplist_del_more(T first, T last);
    int Ziplist_size();
    int Ziplist_size_bytes();
    bool Ziplist_find();
};

#endif
