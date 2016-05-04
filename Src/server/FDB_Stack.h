/*************************************************************************
	> File Name: FDB_Stack.h
	> Author: wrx
	> Mail: 1721267632@qq.com
	> Created Time: 2016年04月18日 星期一 08时03分31秒
 ************************************************************************/

#ifndef _FDB_STACK_H
#define _FDB_STACK_H

#include<iostream>
#include<stack>
#include<mutex>

template <typename T>
class FDB_Stack
{
private:
    std::stack<T> data;		//栈数据对象
    unsigned int size; 		//栈中对象的个数
    std::mutex stack_mutex; 	//栈类中的锁
public:
    FDB_Stack();  			//构造函数
    bool FDB_Stack_empty();		//判断栈是否为空
    void FDB_Stack_pop(); 		//出栈，从栈中删除
    void FDB_Stack_push(const T &rhs);  //向栈添加元素
    T FDB_Stack_top(); 			//读取栈首元素
    unsigned int FDB_Stack_size(); 	//返回栈元素个数
    void FDB_Stack_destory();
};

template <typename T>
FDB_Stack<T>::FDB_Stack()
{
    size = 0;
}

template <typename T>
bool FDB_Stack<T>::FDB_Stack_empty()
{
    while (1)
    {
        if (stack_mutex.try_lock())
        {   
            if (size == 0)
            {
                stack_mutex.unlock();
                return true;
            }
            else 
            {
                stack_mutex.unlock();
                return false;
            }
        }
    }
}

template <typename T>
void FDB_Stack<T>::FDB_Stack_pop()
{
    while (1)
    {
        if (stack_mutex.try_lock())
        {   
            if (size == 0)
            {
            stack_mutex.unlock();
                break;
            }
            data.pop();
            size--;
            stack_mutex.unlock();
            break;
        }
    }
}

template <typename T>
void FDB_Stack<T>::FDB_Stack_push(const T &rhs)
{
    while (1)
    {
        if (stack_mutex.try_lock())
        {   
            data.push(rhs);
            size++;
            stack_mutex.unlock();
            break;
        }
    }
}

template <typename T>
T FDB_Stack<T>::FDB_Stack_top()
{
    return data.top();
}

template <typename T>
unsigned int FDB_Stack<T>::FDB_Stack_size()
{
    while (1)
    {
        if (stack_mutex.try_lock())
        {   
            int st = size;
            stack_mutex.unlock();
            return st;
        }
    }
}

template <typename T>
void FDB_Stack<T>::FDB_Stack_destory()
{
    while(1)
    {
        if (stack_mutex.try_lock())
        {
            size = 0;
            std::stack<T>().swap(data);
            stack_mutex.unlock();
            break;
        }
    }
}

#endif
