
#include<iostream>
#include<vector>
#include<functional>
#include<cstdio>
#include<algorithm>


#define MY_SHORT 1
#define MY_INT 2
#define MY_LONG 3

using namespace std;

class my_intset
{
private:
    long counts;           /*整数集合包含的元素个数*/
    long size_counts;      /*整数集合占用的内存字节数*/
    vector<short> v1;
    vector<int> v2;
    vector<long> v3;
    int tra;            /*类型转换的次数*/

public: 

    /*一组重载向集合插入函数*/
    void my_insert(short s);
    void my_insert(int s);
    void my_insert(long s);

    /*重载从集合中删除元素*/
    bool intset_delete(short s);
    bool intset_delete(int s);
    bool intset_delete(long s);

    my_intset();                    /*构造函数*/
    ~my_intset();                   /*析构函数*/

    void print_int();              /*输出vector函数*/
    int get_size();                /*返回集合中元素的个数*/
    int get_bit_size();            /*返回整数集合占用的内存字节数*/
    int my_less_sort();            /*给集合按升序排序*/
    int my_greater_sort();         /*给集合按降序排序*/
     
    /*重载从集合中查找元素*/
    bool find_intset(short s);
    bool find_intset(int s);
    bool find_intset(long s);

};
