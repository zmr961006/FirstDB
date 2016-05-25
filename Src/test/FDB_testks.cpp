/*************************************************************************
	> File Name: FDB_testks.cpp
	> Author:Eval 
	> Mail:1040460587@qq.com 
	> Created Time: 2016年05月04日 星期三 10时33分14秒
 ************************************************************************/
#include"FDB_ks.h"
int main(int argc,char *argv[])
{
    passwd s("chinaasdfgh",3);
    s.my_output();
    s.encryption();
    s.my_output();
    s.decrypt();
    s.my_output();

    return 0;
}
