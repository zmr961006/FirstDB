//
// Created by butter on 16-7-26.
//

#ifndef MY_NETLIB_USER_H
#define MY_NETLIB_USER_H

#include <iostream>
#include <vector>
#include "FDB_Accept.h"

class FDB_Users {

public:

    FDB_Users();
    ~FDB_Users() = default;

    void User_add(FDB_Accept rhs);

    bool User_del(int rhs_fd);
    bool User_mod();
    bool User_find(int rhs_fd);
    bool User_show();

    FDB_Accept get_Accepter(int rhs_fd);


private:

    std::vector <FDB_Accept> m_vct_Acpt_User_data;

};


#endif //MY_NETLIB_USER_H
