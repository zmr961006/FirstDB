/*************************************************************************
	> File Name: FDB_thread_pool.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月11日 星期一 16时06分55秒
 ************************************************************************/

#include<iostream>
#include"./FDB_thread_pool.h"
using namespace std;

ThreadPool::ThreadPool(const std::string &name):name_(name),maxQueueSize_(0),running_(false){  
                    /*线程池构造*/
}



ThreadPool::~ThreadPool(){    /*析构函数*/

    if(running_){
        stop();
    }
}


void ThreadPool::start(int threadNums){      /*启动线程池*/
    
    assert(threads_.empty() && threadNums > 0);    /*判断容器为空并且线程数是0*/
    running_ = true;
    threads_.reserve(threadNums);                  /*保留适当的容量*/
    for(int i = 0;i < threadNums;++i){             /*创建我们需要预创建的线程*/
        threads_.push_back(new std::thread(&ThreadPool::threadFunc,this));
    }


}


void ThreadPool::stop(){                            /*销毁线程池*/
    { 
        std::lock_guard<std::mutex> lock(mutex_);   /*上锁*/
        running_ = false;
        notEmptyCond_.notify_all();                 /*唤醒所有线程准备结束*/
    
    }
    for(auto & thread: threads_){                   /*结束所有的线程*/ 
        thread->join();
        delete thread;
    }


}


void ThreadPool::pushTask(Task task){                          /*线程池添加任务*/
    
    if(threads_.empty()){                                     /*如果为空直接执行*/
        task();
    }else{
        std::unique_lock<std::mutex> lock(mutex_);            /*加锁*/
        while(isFull()){                                      /*如果队列已经满了，不满条件变量等待*/
            notFullCond_.wait(lock);
        }
        assert(!isFull());
        queue_.push_back(task);                               /*加入任务队列*/
        notEmptyCond_.notify_all();                           /*不空条件变量唤醒*/

    }


}



ThreadPool::Task ThreadPool::take(){                                          /*返回任务队列中的任务*/
    
    std::unique_lock<std::mutex> lock(mutex_);                                /*加锁*/
    while(queue_.empty() && running_){                                        /*任务队列为空，设置不空条件变量*/
        notEmptyCond_.wait(lock);
    }

    Task task;
    if(!queue_.empty()){                                                       /*如果队列不为空*/
        task = queue_.front();                                                   
        queue_.pop_front();
        if(maxQueueSize_ > 0){
            notFullCond_.notify_one();
        }
    }

    return task;                                                              /*返回一个任务，唤醒一个线程*/

}

void ThreadPool::threadFunc(){                                                /*线程池回调函数*/
    
    if(threadInitCallback_){
        threadInitCallback_();
    }
    while(running_){
        Task task(take());
        if(task){
            task();
        }
    }


}

