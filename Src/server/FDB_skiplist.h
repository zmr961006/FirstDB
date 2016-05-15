/*************************************************************************
	> File Name: FDB_skiplist.h
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月14日 星期六 23时32分37秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;


template<class E>
class SkipNode{
public:

    /*构造函数*/
    SkipNode(int size){link = new SkipNode<E>*[size];}

   /*关系运算符重载为类的友元函数*/
    friend int operator<(SkipNode<E> t1, SkipNode<E> t2)
    {
        if(t1.data < t2.data){
            return 1;
        }else{
            return 0;
        }
    }

    friend int operator>(SkipNode<E> t1, SkipNode<E> t2)
    {
        if(t1.data > t2.data){
            return 1;
        }else{
            return 0;
        }
    }

    friend int operator==(SkipNode<E> t1, SkipNode<E> t2)
    {
        if(t1.data == t2.data){
            return 1;
        }else{
            return 0;
        }
    }


    /*成员函数*/
    void set_data(E m){data = m;}
    ~SkipNode(){delete []link;}
    E get_data(){return data;}
    SkipNode<E>** link;              /*一维指针数组*/


private:
    E data;             

};

template<class E>
class list_skip{
public:

    list_skip(E large, int MaxE = 10000, float p=0.5);  /*构造函数*/
    list_skip() = default;
    ~list_skip();                                       /*析构函数*/

    int level();                                        /*产生随机级号*/
    int Insert(E e);                                    /*向跳跃表中插入元素*/

    bool Delete_my(E e);                                /*从跳跃表中删除指定元素e*/
    E Search_my(E e);                                   /*在跳跃表中查找指定的值*/

    void out_my();


private:
    int maxlevel;          /*跳跃表所允许的最大级数*/
    int levels;            /*已存在的非空层数*/
    SkipNode<E>* head;     /*跳跃表的头指针*/
    SkipNode<E>* tail;     /*尾结点指针*/
    SkipNode<E>** last;
    int Eval;              /*用于确定级号*/
    E Tail_key;            /*限定结点值在一定范围内*/

};

