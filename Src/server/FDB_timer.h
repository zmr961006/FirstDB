/*************************************************************************
	> File Name: FDB_timer.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月12日 星期二 14时33分16秒
 ************************************************************************/

#ifndef _FDB_TIMER_H
#define _FDB_TIMER_H

#include<iostream>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdint.h>
#include<sys/timerfd.h>



class timer{

    public:
        timer();
        ~timer();                     /*定时，是否为循环定时的定时器*/
        bool timer_loop(int sec,unsigned long times,int sectimes,bool loop);
        bool timer_settime();
        bool timer_test();
        bool timer_re();
    private:
        int fd;
        int sec_time;                  /*定时时间*/
        int sec_times;                 /*定时触发间隔时间*/
        bool flag;                     /*是否循环定时标志位*/
        unsigned long time_s;          /*定时次数*/ 
        struct timespec now;           /*现在时间*/
        struct itimerspec  new_value;  /*定时器时间结构*/

    


};





#endif
