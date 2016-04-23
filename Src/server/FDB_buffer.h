/*************************************************************************
	> File Name: FDB_buffer.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月17日 星期日 19时15分32秒
 ************************************************************************/

#ifndef _FDB_BUFFER_H
#define _FDB_BUFFER_H


#include<vector>

class Buffer{

    public:
            
        Buffer() = default;
        Buffer(int read_l,int write_l);
        ~Buffer() = default;
        
        int connfd_read(char *str);    

        int return_read_length();
        int re_read_flash();
            
        int connfd_write(std::string str,int ues_less,int length);    

        int return_write_length();
        int re_write_flash();
        
        
    
    
    private:

        int write_index_start;                    /*read and write index */
        int write_index_end  ;
        int read_index_start ;
        int read_index_end   ;
        
        int read_length      ;                    /*read and write = ( start - end )*/
        int write_length     ;
        
        int read_max         ;
        int write_max        ;

        std::vector<char>  read_buff_;
        std::vector<char>  write_buff_;

};




#endif
