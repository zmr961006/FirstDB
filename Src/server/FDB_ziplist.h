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
    std::vector<T> data;            //vector容器列表
public:
    Ziplist() {  }                  
    Ziplist(std::vector<T> rhs);    //以另一个vector容器初始化
    ~Ziplist() {  } 
    void Ziplist_add(T rhs);        //添加一个结点
    void Ziplist_del(T rhs);        //删除指定结点
    bool Ziplist_del_more(T first, T last);     //删除指定的连续的结点
    int Ziplist_size();             //返回列表目前结点数量
    int Ziplist_size_bytes();       //返回列表目前占用内存子字节数
    bool Ziplist_find(T rhs);       //查找链表内是否由指定值的结点
    void Ziplist_show();            //测试函数，用来打印列表的信息
    std::vector<T> Ziplist_return();
    void Ziplist_destory();
};

template <typename T>
Ziplist<T>::Ziplist(std::vector<T> rhs)
{
    data = rhs;
}

template <typename T>
void Ziplist<T>::Ziplist_add(T rhs)
{
    data.push_back(rhs);
}

template <typename T>
void Ziplist<T>::Ziplist_del(T rhs)
{
    for (auto item = data.begin(); item != data.end(); item++)
    {
        if (*item == rhs)
        {
            data.erase(item);
        }
    }
}

template <typename T>
bool Ziplist<T>::Ziplist_del_more(T first, T last)
{
    for (auto item = data.begin(); item != data.end(); item++)
    {
        if (*item == first)
        {
            for (auto iterr = item; iterr != data.end(); iterr++)
            {
                if (*iterr == last)
                {
                    data.erase(item, ++iterr);
                    return true;
                }
            }
            return false;
        }
        else if (*item == last)
        {
            for (auto iterr = item; iterr != data.end(); iterr++)
            {
                if (*iterr == first)
                {
                    data.erase(item, ++iterr);
                    return true;
                }
            }
            return false;
        }
    }
}

template <typename T>
int Ziplist<T>::Ziplist_size()
{
    return data.size();
}

template <typename T>
int Ziplist<T>::Ziplist_size_bytes()
{
    return (data.size() * sizeof(T));
}

template <typename T>
bool Ziplist<T>::Ziplist_find(T rhs)
{
    for (auto item : data)
    {
        if (item == rhs)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void Ziplist<T>::Ziplist_show()
{
    for (auto item : data)
    {
        std::cout << item << "   ";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> Ziplist<T>::Ziplist_return()
{
    return data;
}

template <typename T>
void Ziplist<T>::Ziplist_destory()
{
    std::vector<T>().swap(data);
}

#endif
