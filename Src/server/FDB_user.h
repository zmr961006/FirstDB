/*************************************************************************
	> File Name: FDB_user.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 15时14分15秒
 ************************************************************************/

#ifndef _FDB_USER_H
#define _FDB_USER_H


class User{

    public:
            
        User();    

        void User_add(const Accept &rhs);
        bool User_del(int rhs_fd);
        //bool User_mod();
	bool User_find(int rhs_fd);
 	Accept User_return(int rhs_fd);
    
    private:
        
        std::vector<Accept>  User_data;
            

};


#endif
