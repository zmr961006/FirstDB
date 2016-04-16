/*************************************************************************
	> File Name: FDB_thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月11日 星期一 18时54分56秒
 ************************************************************************/

#include<iostream>
#include"../server/FDB_thread_pool.h"
#include"../server/FDB_thread_pool.cpp"
using namespace std;



int fun(){

    std::cout << "1" << std::endl;
}


int main(){

    ThreadPool pool("name");
    pool.setMaxQueueSize(10);
    pool.start(4);
    for(int i = 1;i <= 100;i++){
        pool.pushTask(std::bind(fun));
    }

    
}


