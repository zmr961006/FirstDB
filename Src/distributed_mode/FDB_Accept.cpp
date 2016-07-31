//
// Created by butter on 16-7-26.
//

#include "FDB_Accept.h"


FDB_Accept::FDB_Accept(int request_fd) {

/*    m_iSock_fd = request_fd;*/
    m_iAccepted_fd = accept(request_fd, (struct sockaddr*)&m_Client_addr, &m_cli_AddrLength);

    if(  -1 == m_iAccepted_fd)
        std::cout << "accept ERROR!" << std::endl;

}


int FDB_Accept::getAccepted_fd() {

    return m_iAccepted_fd;
}




/**********************************************************************************************/


/*
int FDB_Accept::Accept_write(char * str) {

    char buf[1024];
    memcpy(buf, str, 1024);
    ssize_t write_bites = write(m_iAccepted_fd, buf, 1024);

    if(0 < write_bites)
    {
//        connfd_buf.connfd_write(str);
    }
}


int FDB_Accept::Accept_read(char * str) {

    char buf[1024];
    memcpy(buf, str, 1024);
    ssize_t read_bites = read(m_iAccepted_fd, buf, 1024);

    if( 0 < read_bites)
    {
//        connfd_buf.connfd_read(str);
    }
}


*/


FDB_Accept::~FDB_Accept() {

}
