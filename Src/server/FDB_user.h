/*************************************************************************
	> File Name: FDB_user.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 15时14分15秒
 ************************************************************************/

#ifndef _FDB_USER_H
#define _FDB_USER_H

#include<iostream>
#include<vector>
#include"./FDB_accept.h"

class Accept;

class User
{
    private: 

        std::vector<Accept>  User_data;

    public:
        User();    

        void User_add(Accept rhs);
        bool User_del(int rhs_fd);
        bool User_mod();
	    bool User_find(int rhs_fd);
        bool User_show();
 	    Accept User_return(int rhs_fd);
};


#endif
