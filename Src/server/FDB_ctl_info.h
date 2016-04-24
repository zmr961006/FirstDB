/*************************************************************************
	> File Name: FDB_ctl_info.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 17时59分42秒
 ************************************************************************/

#ifndef _FDB_CTL_INFO_H
#define _FDB_CTL_INFO_H

#include<iostream>
#include<fstream>
#include"./FDB_IO.h"

class Ctl_info{

    public:

        Ctl_info() = default;
        ~Ctl_info() = default;
        bool read_info();
        bool write_info();
        bool read_info__(std::fstream & s);
        bool read_info_select(std::string temp,std::string b);
        bool show_all();


    private:
        
        int epoll_num;
        int connfd_num;
        int master;
        int slave ;
        int slave_num;
        int cluster;
        std::string slave_ip_port1;
        std::string slave_ip_port2;
        std::string slave_master;
        

};


#endif
