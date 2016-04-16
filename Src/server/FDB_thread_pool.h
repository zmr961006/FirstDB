/*************************************************************************
	> File Name: FDB_thread_pool.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月11日 星期一 14时41分07秒
 ************************************************************************/

#ifndef _FDB_THREAD_POOL_H
#define _FDB_THREAD_POOL_H

#include<queue>
#include<vector>
#include<string>
#include<mutex>
#include<functional>
#include<thread>
#include<condition_variable>
#include<assert.h>
#include"./FDB_nocopyable.h"

class ThreadPool{
    
    typedef std::function<void()> Task;

    public:
        ThreadPool(){};               /*这个类不可复制*/
        ~ThreadPool();
        ThreadPool(ThreadPool &) = delete;
        ThreadPool & operator = (const ThreadPool &) = delete;
    
        explicit ThreadPool(const std::string &name = std::string());   /*线程池构造*/
        
        void start(int threadNums);                                     /*启动线程池*/

        void stop();                                                    /*结束线程池*/

        void pushTask(Task task);                                       /*线程池添加任务*/

        void setThreadPoolInitCallback(Task  callback){                 /*设置线程初始化回调*/
                threadInitCallback_ = callback;   
        }
        
        void setMaxQueueSize(size_t maxSize) {                          /*设置任务队列最大长度*/
                maxQueueSize_ = maxSize;
        }

        size_t queueSize() const {                                      /*当前任务队列长度*/
            std::lock_guard<std::mutex> lock(mutex_);
            return queue_.size();
        }
    
    private:
        bool isFull() const{
            assert(!mutex_.try_lock());
            return maxQueueSize_ > 0 && queue_.size() >= maxQueueSize_;
        }
        
        Task take();
        void threadFunc();

        std::string name_; 
        size_t maxQueueSize_;                                           /*任务队列最大长度*/
        bool running_;

        mutable  std::mutex mutex_;                                     /*线程池的锁*/
        std::condition_variable notFullCond_;                           /*条件变量未满*/
        std::condition_variable notEmptyCond_;                          /*条件变量不为空*/
        
        Task threadInitCallback_;                                       /*回调函数*/
        std::vector<std::thread*> threads_;                             /*线程池*/
        std::deque<Task> queue_;                                        

};






#endif
