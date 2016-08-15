/*************************************************************************
	> File Name: test_judge.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年08月14日 星期日 20时23分28秒
 ************************************************************************/


#include"FDB_judge_commd.h"
using namespace std;
int main(int argc,char *argv[])
{
    judge_commd A;
    char s[128];
    int m;
    while(1)
    {
     
        std::cout << "input:" << std::endl;
        cin >> s >> m;
        std::cout << A.judge_commd_func(s, m) << std::endl;

    }

    return 0;
}
