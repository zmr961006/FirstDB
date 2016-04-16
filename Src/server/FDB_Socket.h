/*************************************************************************
	> File Name: FDB_Socket.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月14日 星期四 08时14分50秒
 ************************************************************************/

#ifndef _FDB_SOCKET_H
#define _FDB_SOCKET_H

struct tcp_info;

class Socket{

    public:
        explicit Socket(int sockfd):sockfd_(sockfd){}
    
        bool Socket__(sa_family_t family = AF_INET,int backlog);
        ~Socket();
        int fd()const{return sockfd_; }
        bool Socket(sa_family_t family,int listen_num);
        bool getTcpInfo(struct tcp_info *)const;
        bool getTcpInfoString(char *buf,int len)const;
    
        bool bindAddress(struct sockaddr * localaddr);
        bool listen(int backlog);

        int accept(InetAddress *peeraddr);
        bool shutdownWrite();
        bool setTcpNoDelay(bool on);
        bool setReuseAddr(bool on);
        bool setReusePort(bool on);
        int setnonblocking();    

        bool setKeepAlive(bool on);


    private:
        int sockfd_ ;
        int backlog;
        struct sockaddr_in address;mZ        
        


};






#endif
