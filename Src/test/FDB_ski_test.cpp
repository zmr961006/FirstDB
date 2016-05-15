/*************************************************************************
	> File Name: FDB_ski_test.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月14日 星期六 23时35分17秒
 ************************************************************************/

#include "FDB_skiplist.h"
using namespace std;

int main(int argc,char *argv[])
{
    list_skip<long>ju(1000);

    ju.Insert(400);
    ju.Insert(200);
    ju.Insert(300);
    ju.Insert(400);
    ju.Insert(100);
    
    ju.Insert(200);
    ju.out_my();


    ju.Delete_my(200);
    ju.out_my();
    return 0;
}
