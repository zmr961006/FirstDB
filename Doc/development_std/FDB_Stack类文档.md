##类的名称（编号）
  类的文件命名规则：  
  FDB_Stack.h   
##类的声明与作用
  栈数据结构在多项程下的实现
###类开发的必要性，唯一性
  用加锁的方式完成对栈在多线程下的实现的可能。而stack模版却并不支持多线程的使用。
###类中各函数的复杂度，可能瓶颈
  
##类的声明与定义
  贴出类的声明，相应注释
```
    bool FDB_Stack_empty();		//判断栈是否为空
    void FDB_Stack_pop(); 		//出栈，从栈中删除
    void FDB_Stack_push(const T &rhs);  //向栈添加元素
    T FDB_Stack_top(); 			//读取栈首元素
    unsigned int FDB_Stack_size(); 	//返回栈元素个数
```
###类成员函数接口说明
    1.接口：bool FDB_Stack_empty();	
    
    功能：判断栈是否为空
    
    参数：无参数
    
    2.接口：void FDB_Stack_pop(); 		
    
    功能：出栈，从栈中删除
    
    参数：无参数
    
    3.void FDB_Stack_push(const T &rhs);  
    
    功能：向栈添加元素
    
    参数：传递push的元素
    
    4.T FDB_Stack_top(); 
    
    功能：读取栈首元素
    
    参数：无参数
    
    5.unsigned int FDB_Stack_size();
    
    功能：返回栈元素个数
    
    参数：无参数
###审阅人批覆