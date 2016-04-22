/*************************************************************************
	> File Name: FDB_timer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月19日 星期二 13时21分36秒
 ************************************************************************/

#include<iostream>
#include"./FDB_timer.h"


/*int main(){

    bool f_flag = true;
    struct timespec now;
    struct itimerspec new_value;
    clock_gettime(CLOCK_REALTIME,&now);
    
    new_value.it_value.tv_sec = now.tv_sec + 3;
    new_value.it_value.tv_nsec = now.tv_nsec;

    new_value.it_interval.tv_nsec = 0;

    int fd = timerfd_create(CLOCK_REALTIME,TFD_NONBLOCK);
    
    f_flag = false;
    
    char buf[1];
    uint64_t exp;
    timerfd_settime(fd,TFD_TIMER_ABSTIME,&new_value,NULL);

    while(1){
        
        int s = read(fd,&exp,sizeof(uint64_t));
        if(s != sizeof(uint64_t)){
            std::cout << "hhhh \n" << std::endl;
        }else{
            std::cout << "get \n" << std::endl;
        }
    }
}*/


timer::~timer(){

    close(fd);

}


timer::timer(){
    
        fd = timerfd_create(CLOCK_REALTIME,TFD_NONBLOCK);

}



bool timer::timer_loop(int sec,unsigned long times,int sectimes,bool loop){
    
    flag = loop;
    time_s = times;
    sec_time = sec;
    sec_times = sectimes;
    if(loop){
        
           
            timer_settime();    
        
    }else{
        
                    
            timer_settime();  
                
        
    }

}



bool timer::timer_settime(){
     
    if(clock_gettime(CLOCK_REALTIME,&now) == -1){
        
        std::cout << "set :time error "<< __LINE__ << std::endl;    
        
    }
    
    new_value.it_value.tv_sec = now.tv_sec + sec_time;
    new_value.it_value.tv_nsec = now.tv_nsec;

    //std::cout << sec_time << std::endl;
    new_value.it_interval.tv_nsec = 0;
    /*if(sec_times){
        new_value.it_value.tv_sec = sec_times ;

    }else{
        new_value.it_value.tv_sec = 0;

    }*/

    
    timerfd_settime(fd,TFD_TIMER_ABSTIME,&new_value,NULL);
    timer_test();  

}


bool timer::timer_re(){

    return flag;


}

bool timer::timer_test(){
    

    while(1){
        uint64_t exp;
        int s = read(fd,&exp,sizeof(uint64_t));
        if(s != sizeof(uint64_t)){

            //std::cout << "miss time " << std::endl;

        }else{

            std::cout << "get "  << std::endl;
            if(timer_re()){
                std::cout << "SSSSSS" << std::endl;
                timerfd_settime(fd,TFD_TIMER_ABSTIME,0,NULL);
                timer_settime();
                
            }

        }

    }
}




