//
// Created by butter on 16-7-26.
//

#include "FDB_Users.h"

FDB_Users::FDB_Users(){

}


void FDB_Users::User_add(FDB_Accept rhs) {
    m_vct_Acpt_User_data.push_back(rhs);
}


bool FDB_Users::User_del(int rhs_fd) {

    for(auto item = m_vct_Acpt_User_data.begin(); item != m_vct_Acpt_User_data.end(); item++)
    {
        if((*item).getAccepted_fd() == rhs_fd) {
            m_vct_Acpt_User_data.erase(item);
            return true;
        }
    }

    return false;
}


bool FDB_Users::User_mod() {

}


bool FDB_Users::User_find(int rhs_fd) {

    int size = 0;
    for(auto item : m_vct_Acpt_User_data){

        size++;
        if(rhs_fd == item.getAccepted_fd())
            return true;
    }
    std::cout << size << std::endl;
    return false;
}


bool FDB_Users::User_show() {

    for(auto item:m_vct_Acpt_User_data)
        std::cout << "On line user acpted_fd: " <<item.getAccepted_fd() << std::endl;

    return true;
}

FDB_Accept FDB_Users::get_Accepter(int rhs_fd) {

    for(auto item : m_vct_Acpt_User_data)
    {
        if(rhs_fd == item.getAccepted_fd())
            return item;
    }
   // return NULL;
}

