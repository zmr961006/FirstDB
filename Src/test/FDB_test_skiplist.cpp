/*************************************************************************
	> File Name: test_skiplist.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年04月16日 星期六 12时58分11秒
 ************************************************************************/
#include<stdio.h>  
#include"SkipList.h"

int main()  
{  
    skiplist<int> A;
    skiplist<int > *sl=A.createSkiplist();  
    for(int i=1;i<=19;i++)  
    {  
        A.insert(sl,i,i*2);  
    }  
    A.printSL(sl);  
    printf("\n\n");
    //搜索  
    int i=A.search(sl,4);  
    printf("i=%d\n",i);  
    //删除  
    int b=A.deleteSL(sl,4);  
    if(b)  
    printf("删除成功\n");  
    A.printSL(sl);  
    return 0;  
}  


