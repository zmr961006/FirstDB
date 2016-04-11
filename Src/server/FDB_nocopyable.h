/*************************************************************************
	> File Name: FDB_nocopyable.h
	> Author: 
	> Mail: 
	> Created Time: 2016年04月11日 星期一 14时45分03秒
 ************************************************************************/

#ifndef _FDB_NOCOPYABLE_H
#define _FDB_NOCOPYABLE_H

class nocopyable{
    protected:
        nocopyable(){}
        ~nocopyable(){}
    private:
        nocopyable(const nocopyable &);
        const nocopyable & operator=(const nocopyable &);
};




#endif
