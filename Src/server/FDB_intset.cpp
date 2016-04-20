/*************************************************************************
	> File Name: intset.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年04月17日 星期日 16时27分26秒
 ************************************************************************/


using namespace std;
#include"FDB_intset.h"

/*构造函数*/
my_intset::my_intset()
{
    tra = MY_SHORT;
    counts = 0;
    size_counts = 0;

}

/*析构函数*/
my_intset::~my_intset()
{
    for(auto i = v1.end()-v1.begin(); i > 0; i--){
        v1.push_back( *(v1.begin()+i) );
    }
    for(auto i = v2.end()-v2.begin(); i > 0; i--){
        v2.push_back( *(v2.begin()+i) );
    }
    for(auto i = v3.end()-v3.begin(); i > 0; i--){
        v3.push_back( *(v3.begin()+i) );
    }
}
/*一组重载的向集合插入元素函数*/
void my_intset::my_insert(short s)
{
    if(tra == MY_SHORT){
        v1.push_back(s);
    }else if(tra == MY_INT){
        v2.push_back(s);
    }else if(tra == MY_LONG){
        v3.push_back(s);
    }
}

void my_intset::my_insert(int s)
{
    if(tra == MY_SHORT){
        for(auto &i : v1){
            v2.push_back(i);
        }
        v2.push_back(s);
        tra = MY_INT;                 /*由short类型转为int类型，改变tra值为MY_INT*/
    }else if(tra == MY_INT){
        v2.push_back(s);
    }else if(tra == MY_LONG){
        v3.push_back(s);
    }
}
void my_intset::my_insert(long s)
{
    if(tra == MY_SHORT){
        for(auto &i : v1){
            v3.push_back(i);
        }
    }else if(tra == MY_INT){
        for(auto &i : v2){
            v3.push_back(i);
        }
    }

    tra = MY_LONG;           /*一旦有一个long类型值插入集合就必须为long类型，改变tra值为MY_LONG */
    v3.push_back(s);
}


/*输出集合函数*/
void my_intset::print_int()
{
    if(tra == MY_SHORT){
        for(auto &i : v1){
            std::cout << i << std::endl;
        }
    }
    if(tra == MY_INT){
        for(auto &i : v2){
            std::cout << i << std::endl;
        }
    }
    if(tra == MY_LONG){
        for(auto &i : v3){
            std::cout << i << std::endl;
        }
    }
    
}

/*对集合中元素按照升序排序*/
int my_intset::my_less_sort()
{
    if(tra == MY_SHORT){
        sort(v1.begin(), v1.end(),less<short>());
    }
    if(tra == MY_INT){
        sort(v2.begin(), v2.end(),less<int>());
    }
    if(tra == MY_LONG){
        sort(v3.begin(), v3.end(),less<long>());
    }

    return 0;
}

/*对集合中元素按照降序排序*/
int my_intset::my_greater_sort()
{
    if(tra == MY_SHORT){
        sort(v1.begin(), v1.end(),greater<short>());
    }
    if(tra == MY_INT){
        sort(v2.begin(), v2.end(),greater<int>());
    }
    if(tra == MY_LONG){
        sort(v3.begin(), v3.end(),greater<long>());
    }

    return 0;
}


/*返回整数集合包含的元素个数*/
int my_intset::get_size(){
    if(tra == MY_SHORT){
        counts = v1.size();
    }
    if(tra == MY_INT){
        counts = v2.size();
    }
    if(tra == MY_LONG){
        counts = v3.size();
    }
    return counts;
}

/*返回整数集合占用的内存字节数*/
int my_intset::get_bit_size(){
    if(tra == MY_SHORT){
        return (counts*2);
    }
    if(tra == MY_INT){
        return (v2.size()*4);
    }
    if(tra == MY_LONG){
        return (v3.size()*8);
    }
}


/*一组重载的从整数集合中移除给定元素函数*/
bool my_intset::intset_delete(short s){

    if (tra != MY_SHORT){
        std::cout << "移除的元素或元素类型不存在" << std::endl;
        return false;
    }
    for(auto i = v1.begin(); i != v1.end(); i++){
        if(*i == s){
            v1.erase(i);
        }
    }

    return true;
}

bool my_intset::intset_delete(int s){

    if (tra != MY_INT){
        std::cout << "移除的元素或元素类型不存在" << std::endl;
        return false;
    }
    for(auto i = v2.begin(); i != v2.end(); i++){
        if(*i == s){
            v2.erase(i);
        }
    }

    return true;
}

bool my_intset::intset_delete(long s){

    if (tra != MY_LONG){
        std::cout << "移除的元素或元素类型不存在" << std::endl;
        return false;
    }
    for(auto i =v3.begin(); i != v3.end(); i++){
        if(*i == s){
            v3.erase(i);
        }
    }
}

/*一组重载的在vector中查找指定的元素*/
bool my_intset::find_intset(short s)
{

    if(tra == MY_INT){
        int m = s;
        return find_intset(m);
    }
    if(tra == MY_LONG){
    
        long m = s;
        return find_intset(m);
    }

    this->my_less_sort();
    //v1.my_less_sort();           /*先给集合按升序排序*/
    int found = 0;                 /*二分法（又叫折半查找法）查找数组a */ 
    int mid;
    int low = 0;  
    int high = v1.size();  
    while(low <= high)  
    {
        mid = (high+low)/2;
        auto i = v1.begin()+mid;
        
        if(*i == s)  
        {  
            found=1;  
            break;  
        }  

        if(*i < s){
            low = mid+1;          /*mid往右移动*/  
        }else{
            high = mid-1;         /*mid往左移动右逢源*/ 
        }  

    }
    if (found)              /*fond的初始值为0，一旦找到，found变量被置1,引发此条件语句，从而输出找到的结果，否则告知用户找不到。*/
       return true;
    
    std::cout << "查找的元素不存在" << std::endl;
    return false;
}


bool my_intset::find_intset(int s)
{

    if(tra == MY_LONG){
    
        long m = s;
        return find_intset(m);
    }
    
    if(tra == MY_SHORT){
        std::cout << "查找的元素或者类型不存在" << std::endl;
        return false;
    }

    this->my_less_sort();           /*先给集合按升序排序*/

    int found = 0;                    /*二分法（又叫折半查找法）查找数组a  */
    int mid;
    int low = 0;  
    int high = v2.size();  
    while(low <= high)  
    {
        mid = (high+low)/2;
        auto i = v2.begin()+mid;
        
        if(*i == s)  
        {  
            found=1;  
            break;  
        }  

        if(*i < s){
            low = mid+1;          /* mid往右移动*/ 
        }else{
            high = mid-1;         /* mid往左移动右逢源 */ 
        }  

    }
    if (found)              /* fond的初始值为0，一旦找到，found变量被置1,引发此条件语句，从而输出找到的结果，否则告知用户找不到。*/
       return true;
    
    std::cout << "查找的元素不存在" << std::endl;
    return false;
}


bool my_intset::find_intset(long s)
{

    if(tra != MY_LONG){
        std::cout << "查找的元素或者类型不存在" << std::endl;
        return false;
    }

    this->my_less_sort();           /*先给集合按升序排序*/
    int found = 0;                    /* 二分法（又叫折半查找法）查找数组a  */
    int mid;
    int low = 0;  
    int high = v3.size();  
    while(low <= high)  
    {
        mid = (high+low)/2;
        auto i = v3.begin()+mid;
        
        if(*i == s)  
        {  
            found=1;  
            break;  
        }  

        if(*i < s){
            low = mid+1;          /* mid往右移动 */ 
        }else{
            high = mid-1;         /* mid往左移动右逢源*/  
        }  

    }
    if (found)              /* fond的初始值为0，一旦找到，found变量被置1,引发此条件语句，从而输出找到的结果，否则告知用户找不到。*/
       return true;
    
    std::cout << "查找的元素不存在" << std::endl;
    return false;
}

