/*************************************************************************
	> File Name: FDB_ctl_info.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月21日 星期四 17时59分32秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include"./FDB_ctl_info.h"
#include<cstdlib>


bool Ctl_info::read_info(){

    std::fstream ccin("../FDB.ctl");
    if(!ccin){
        std::cout << "error" << std::endl;
    }else{
    
        while(ccin){
            
            read_info__(ccin);
            //break;

        }
        ccin.close();
    }


}


bool Ctl_info::read_info__(std::fstream & s){
    
    std::string a;
    int c;
    s >> a;
    int len = 0;
    int length = a.length();
    if(length == 0){
        return false;
    }
    while(a[len] != ']'){
        len++;
    }
    len++;
    std::string obj(a,0,len);
    len++;
    std::string b(a,len);
    read_info_select(obj,b);   


}


bool Ctl_info::read_info_select(std::string temp,std::string b){
    
    if(temp.compare("[epoll_num]") == 0){

        epoll_num = std::atoi(b.c_str());
        //std::cout << epoll_num << std::endl;

    }else if(temp.compare("[connfd_num]") == 0 ){
        connfd_num = std::atoi(b.c_str());    
            
    }else if(temp.compare("[master]") == 0){
        
        if(b.compare("NO")){
            master = 0;
        }else{
            master = 1;
        }

    }else if(temp.compare("[slave]") == 0){
        
        if(b.compare("NO")){
            slave = 0;
        }else{
            slave = 1;
        }

    }else if(temp.compare("[slave_num]") == 0){
        
        slave_num = std::atoi(b.c_str());

    }else if(temp.compare("[cluster]") == 0){
        
        if(b.compare("NO")){
            cluster = 0;
        }else{
            cluster = 1;
        }

    }else if(temp.compare("[slave_ip_port1]") == 0){
        
        slave_ip_port1 = b;

    }else if(temp.compare("[slave_ip_port2]") == 0){
        
        slave_ip_port2 = b;

    }else if(temp.compare("[cluster_master]") == 0){

        slave_master = b  ;

    }else{
           
    }
        
    return true;
    
}



bool Ctl_info::write_info(){





}


bool Ctl_info::show_all(){


    std::cout << "epoll_num " << epoll_num << std::endl;
    std::cout << "connfd_num " << connfd_num << std::endl;
    std::cout << "master " << master << std::endl;
    std::cout << "slave " << slave << std::endl;
    std::cout << "slave_num " << slave_num << std::endl;
    std::cout << "cluster " << cluster << std::endl;
    std::cout << "slave_ip_port1 " << slave_ip_port1 << std::endl;
    std::cout << "slave_ip_port2 " << slave_ip_port2 << std::endl;
    std::cout << "slave_master " << slave_master << std::endl;
    

}





