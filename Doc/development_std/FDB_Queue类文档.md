##类的名称（编号）
  类的文件命名规则：  
  FDB_Queue.h   
##类的声明与作用
  对列数据结构在多项程下的实现
###类开发的必要性，唯一性
  用加锁的方式完成对对列在多线程下的实现的可能。而queue模版却并不支持多线程的使用。
###类中各函数的复杂度，可能瓶颈
  
##类的声明与定义
  贴出类的声明，相应注释
```
    bool FDB_Queue_empty();     //判断对列是否为空
    void FDB_Queue_pop();       //出队，从队列中删除
    T FDB_Queue_front();        //读取队首元素
    T FDB_Queue_back();         //读取队尾元素
    void FDB_Queue_push(const T &rhs);      //向对列添加元素
    unsigned int FDB_Queue_size();          //返回对列元素个数   
```
###类成员函数接口说明
    1.接口：bool FDB_Queue_empty();	
    
    功能：判断对列是否为空
    
    参数：无参数
    
    2.接口：void FDB_Queue_pop(); 		
    
    功能：出队，从队列中删除
    
    参数：无参数
    
    3.T FDB_Queue_front(); 
    
    功能：读取队首元素
    
    参数：无参数
    
    4.T FDB_Queue_back();
    
    功能：读取队尾元素
    
    参数：无参数
    
    5.void FDB_Queue_push(const T &rhs);  
    
    功能：向对列添加元素
    
    参数：传递push的元素
    
    6.unsigned int FDB_Queue_size();
    
    功能：返回对列元素个数
    
    参数：无参数
###审阅人批覆