
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
    long counts;                           /*集合包含的元素个数*/
    long size_counts;                      /*集合占用的内存字节数*/

    /*如果操作的元素是整数类型的*/
    std::vector<short> v1;
    std::vector<int> v2;
    std::vector<long> v3;

    int tra;                               /*整数类型转换的次数*/
    int bit_size;                          /*集合所占字节数*/

    std::vector<std::string > v4;          /*如果操作的元素是字符类型的*/


public: 

    /*一组重载向集合插入函数*/
    void my_insert(short s);
    void my_insert(int s);
    void my_insert(long s);
    void my_insert(std::string s);

    /*重载从集合中删除元素*/
    bool intset_delete(short s);
    bool intset_delete(int s);
    bool intset_delete(long s);
    bool intset_delete(std::string s);

     my_intset();                     /*构造函数*/
     ~my_intset();                    /*析构函数*/


    void print_int();                 /*输出集合中的元素*/
    int get_size();                   /*返回集合中元素的个数*/
    int get_bit_size();               /*返回集合占用的内存字节数*/
    int my_less_sort();               /*给集合按升序排序*/
    int my_greater_sort();            /*给集合按降序排序*/
     
    /*重载从集合中查找元素*/
    bool find_intset(short s);
    bool find_intset(int s);
    bool find_intset(long s);
    bool find_intset(std::string s);

};
