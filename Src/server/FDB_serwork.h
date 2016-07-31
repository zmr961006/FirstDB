/*************************************************************************
	> File Name: FDB_serwork.h
	> Author: 
	> Mail: 
	> Created Time: 2016年05月04日 星期三 17时06分57秒
 ************************************************************************/

#ifndef _FDB_SERWORK_H
#define _FDB_SERWORK_H


#include<string>
#include"FDB_json.h"


class Server_work{

    private:

        std::string message;
        int connfd_sockfd  ;   

    public:
    
        Server_work(int connfd);
        
        bool do_work();
        int Server_read();
        bool Server_tanslation();
        bool Server_dowork();

};

#endif
