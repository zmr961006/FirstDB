/*************************************************************************
	> File Name: FDB_buffer.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 15时13分09秒
 ************************************************************************/

#include<iostream>
#include"./FDB_buffer.h"


int Buffer::connfd_write(std::string str,int use_less,int length){

    for(int i = length - use_less;i <= length;i++){

        write_buff_.push_back(str[i]);

    }

    return use_less;

}

int Buffer::return_read_length(){
    

    return read_buff_.size();

}



int Buffer::return_write_length(){
    

    return write_buff_.size();


}


