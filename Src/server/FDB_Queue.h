/*************************************************************************
	> File Name: FDB_Queue.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月18日 星期一 09时08分51秒
 ************************************************************************/

#ifndef _FDB_QUEUE_H
#define _FDB_QUEUE_H

#include<iostream>
#include<mutex>
#include<queue>

template <typename T>
class FDB_Queue
{
private:
    std::queue<T> data;              //对列数据对象
    std::mutex queue_mutex;     //对列类中的锁
    unsigned int size;          //对列中对象的个数
public:
    FDB_Queue();                //构造函数
    bool FDB_Queue_empty();     //判断对列是否为空
    void FDB_Queue_pop();       //出队，从队列中删除
    T FDB_Queue_front();        //读取队首元素
    T FDB_Queue_back();         //读取队尾元素
    void FDB_Queue_push(const T &rhs);      //向对列添加元素
    unsigned int FDB_Queue_size();          //返回对列元素个数
    void FDB_Queue_destory();

     FDB_Queue& operator= (const FDB_Queue &a);
}; 
    
template <typename T>
FDB_Queue<T>::FDB_Queue()
{
    size = 0;
}

template <typename T>
bool FDB_Queue<T>::FDB_Queue_empty()
{
    while (1)
    {
        if (queue_mutex.try_lock())
        {   
            if (size == 0)
            {
                queue_mutex.unlock();
                return true;
            }
            else 
            {
                queue_mutex.unlock();
                return false;
            }
        }
    }
}

template <typename T>
void FDB_Queue<T>::FDB_Queue_pop()
{
    while (1)
    {
        if (queue_mutex.try_lock())
        {   
            if (size == 0)
            {
                queue_mutex.unlock();
                break;
            }
            data.pop();
            size--;
            queue_mutex.unlock();
            break;
        }
    }
}

template <typename T>
T FDB_Queue<T>::FDB_Queue_front()
{
    while (1)
    {
        if (queue_mutex.try_lock())
        {
            T tr = data.front();
            queue_mutex.unlock();
            return tr;
        }
    }
}

template <typename T>
T FDB_Queue<T>::FDB_Queue_back()
{
    while (1)
    {
        if (queue_mutex.try_lock())
        {   
            T tr = data.back();
            queue_mutex.unlock();
            return tr;
        }
    }
}

template <typename T>
void FDB_Queue<T>::FDB_Queue_push(const T &rhs)
{
    while (1)
    {
        if (queue_mutex.try_lock())
        {   
            data.push(rhs);
            size++;
            queue_mutex.unlock();
            break;
        }
    }
}

template <typename T>
unsigned int FDB_Queue<T>::FDB_Queue_size()
{
     while (1)
    {
        if (queue_mutex.try_lock())
        {   
            int st = size;
            queue_mutex.unlock();
            return st;
        }
    }
}

template <typename T>
void FDB_Queue<T>::FDB_Queue_destory()
{
    while (1)
    {
        if (queue_mutex.try_lock())
        {
            size = 0;
            std::queue<T>().swap(data);
            queue_mutex.unlock();
            break;
        }
    }
}

template <typename T>
FDB_Queue<T>& FDB_Queue<T>::operator= (const FDB_Queue &a)
{
    size = a.size;
    data = a.data;
}

#endif
