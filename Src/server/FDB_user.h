/*************************************************************************
	> File Name: FDB_user.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月20日 星期三 15时14分15秒
 ************************************************************************/

#ifndef _FDB_USER_H
#define _FDB_USER_H


class User_id{
    
    public:
        
        User_id();
        User_id(int sockaddr,int connfd ,struct sockaddr & u);
        int User_return_conn();
        
    private:
        
        int sockfd_;
        int connfd_;
        int hash;
        struct sockaddr user;
        
};



class User{

    public:
            
        User();    

        User_add();
        User_del();
        User_mod();

    
    private:
        
        std::list<User_id>  User_data;
            

};


#endif
