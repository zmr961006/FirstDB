/*************************************************************************
	> File Name: FDB_user.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 15时31分38秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include"./FDB_user.h"
User::User()
{

}

void User::User_add( Accept rhs)
{
    User_data.push_back(rhs);
}

bool User::User_del(int rhs_fd)
{
    for (auto item = User_data.begin(); item != User_data.end(); item ++)
    {
        if ((*item).Accept_return() == rhs_fd)
        {
            User_data.erase(item);
            return true;
        }
    }
    
    return false;
}

/*bool User::user_mod(Accept rhs)
{
    for (auto item = User_data.begin(); item != User_data.end(); item ++)
    {
        if ((*item).Accept_return() == rhs.Accept_return())
        {
            User_data.erase(item);
            User_data(rhs);
            return true;
        }
    }
    
    return false;
}*/

bool User::User_find(int rhs_fd)
{
int size = 0;
    for (auto item : User_data)
    {
size++;
        if (rhs_fd == item.Accept_return())
        {
            return true;
        }
    }
std::cout << size << std::endl;

    return false;
}

Accept  User::User_return(int rhs_fd)
{
    for (auto item : User_data)
    {
        if (rhs_fd == item.Accept_return())
        {
            return item;
        }
    }
}

bool User::User_show(){

    for(auto item : User_data){
        
        std::cout << item.Accept_return() << std::endl;

    }



}




