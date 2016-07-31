//
// Created by butter on 16-7-26.
//

#include "FDB_Socket.h"
typedef struct sockaddr SA;

/***************************核心构造函数***********************************************/
FDB_Socket::FDB_Socket(sa_family_t family, int listen_num) {

    Socket_createSocket(family, listen_num);

    Socket_setReusePort(true);
    bzero(&m_addr_inAddress, sizeof(m_addr_inAddress));

    m_addr_inAddress.sin_family      = AF_INET;                                             /*协议族*/
    m_addr_inAddress.sin_addr.s_addr = htonl(INADDR_ANY);                                   /*ip*/
    m_addr_inAddress.sin_port        = htons(9201);                                         /*port*/

    if(Socket_bindAddress() && (m_iSockfd > 0)) {                                           /*绑定*/

        if(Socket_listen(listen_num)) {                                                     /*监听*/

            if(Socket_setNoBlocking())                                                      /*非阻塞*/
                return;
        }
    }
}

bool FDB_Socket::Socket_createSocket(sa_family_t family, int listen_num) {                            /*创建一个socket*/

    m_iBacklog = listen_num;
    m_iSockfd =  socket(family, SOCK_STREAM, 0);                                            /*调用socket(),创建一个socket*/


    if( m_iSockfd < 0)
        std::cout << "log_net_error" << std::endl;                                          /*创建socket失败*/

}


bool FDB_Socket::Socket_bindAddress() {

    std::cout << "m_iSockfd = " << m_iSockfd << "  len = " << sizeof(m_addr_inAddress) << std::endl;

    int ret = bind(m_iSockfd, (SA*)&m_addr_inAddress, sizeof(m_addr_inAddress));            /*命名m_iSocket*/

    if(ret < 0){
        std::cout << "bind ERROR!   return " << ret << std::endl;                           /*命名失败*/
        return false;
    }

    return true;

}

bool FDB_Socket::Socket_listen(int backlog) {

    int ret = listen(m_iSockfd, backlog);                                                   /*监听套接字m_iSockfd*/

    if(ret < 0) {
        std::cout << "listen ERROR" <<std::endl;                                            /*监听失败*/
        return false;
    }
    return true;
}

int  FDB_Socket::Socket_do_accept() {                                                       /*测试用，进行链接监听并读取一次*/

    socklen_t client_addr_length;
    int connfd;
    while(1) {

        if(client_addr_length == 0){break;}

        client_addr_length = sizeof(m_addr_inCliaddr);
        connfd = accept(m_iSockfd, (SA*)&m_addr_inCliaddr, &client_addr_length);            /*accept*/
        if(connfd > 0) {
            if(fork() == 0)
            {
                char buf[100];
                while(read(connfd, buf, 100) > 0) {
                    std::cout << buf << std::endl;
                }
            }
        }

    }
}
bool FDB_Socket::Socket_getbacklog(){}
bool FDB_Socket::Socket_shutdownWrite(){}
bool FDB_Socket::Socket_TcpNoDelay(bool on){}



bool FDB_Socket::Socket_setReusePort(bool on) {                                                     /*设置端口重用*/

    int optval = on ? 0 : 1;
    ::setsockopt(m_iSockfd, SOL_SOCKET, SO_REUSEPORT, &optval, static_cast<socklen_t >(sizeof optval));

    return true;

}

bool FDB_Socket::Socket_setResuseAddr(bool on) {                                                    /*设置地址重用*/

    int optval = on ? 1: 0;
    ::setsockopt(m_iSockfd, SOL_SOCKET, SO_REUSEADDR, &optval, static_cast<socklen_t>(sizeof optval));

    return true;

}


bool FDB_Socket::Socket_setTimeOutRecnt(bool on){

    int optval = on ? 1: 0;
    ::setsockopt(m_iSockfd, SOL_SOCKET, SO_SNDTIMEO, &optval, static_cast<socklen_t>(sizeof optval));
}


int  FDB_Socket::Socket_setNoBlocking() {                   /*设置 m_iSockfd 为非阻塞*/

    int old_option = fcntl(m_iSockfd,F_GETFL);
    int new_option = old_option | O_NONBLOCK;
    fcntl(m_iSockfd , F_SETFL, new_option);
    return old_option;
}

bool FDB_Socket::Socket_setKeepAlive(bool on) {             /*保持活着*/

    int optval = on ? 1 : 0;
    ::setsockopt(m_iSockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, static_cast<socklen_t >(sizeof optval));
    return true;
}


bool FDB_Socket::test_accept(){

}

int  FDB_Socket::Socket_getfd(){                            /*获取套接字描述符 m_iSockfd*/
    return m_iSockfd;
}








//bool Socket_getTcpInfo(struct tcp_info *) const;
//bool Socket_getTcpInfoString(char * buf, int len) const;







FDB_Socket::~FDB_Socket() {
    ::close(m_iSockfd);
}
