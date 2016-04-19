##哈希命令

    1.Hash_map();  初始化空哈希表   HMCREAT
    
    2.void Hash_map_add(Hash_node_pseudo<T> rhs);   向哈希表添加键值对    HMADD
    
    3.void Hash_map_del(Hash_node_pseudo<T> rhs);   删除哈希表中的键值对rhs     HMDEL
    
    4.void Hash_map_change(Hash_node_pseudo<T> rhs);  
    将与rhs键值对的键相等的键值对替换为rhs    HMUPDATE
    
    5.void Hash_map_destory();  清空哈希表，并再次初始化它   HMCLEAR
    
    6.T Hash_map_value(String rhs);  返回哈希表中键位rhs的键值对的值    HMVALUE
    
##伪哈希命令

    1.Hash_map_pseudo()；  初始化空伪哈希    HMPCREAT
    
    2.void Hash_pseudo_set(Hash_node_pseudo<T> rhs);  相容器中添加键值对    HMPADD
    
    3.void Hash_pseudo_del(const String & rhs);  在容器中删除指定键的键值对    HMPDEL
    
    4.void Hash_pseudo_change(Hash_node_pseudo<T> rhs);
    将与rhs键值对中键相等的键值对替换为rhs    HMUPDATE
    
    5.T Hash_pseudo_find(const String & rhs);  返回键值对中键为rhs的值    HMPVALUE

    6.int Hash_pseudo_size();  返回容器中保存键值对的数目    HMPSIZE
    
    7.void Hash_pseudo_destory();  消除容器    HMPCLEAR
   
##压缩列表命令

    1.Ziplist()；  初始化压缩列表    ZLCREATE
    
    2.void Ziplist_add(T rhs);  添加一个结点    ZLADD
    
    3.void Ziplist_del_more(T first, T last);  删除指定的连续的结点   ZLADDM
    
    4.int Ziplist_size();  返回列表目前结点数量    ZLSIZE
    
    5.int Ziplist_size_bytes();  返回列表目前占用内存子字节数   ZLSIZEB
    
##字符串
    1.String(); 				    无参构造
      String(char *rhs); 			行参为char* 构造函数
      String(const String &rhs); 	复制构造函数        SCREAT

    
    2.String& operator+=(const String &rhs);  复合赋值运算符
      String& operator+=(const char *rhs); 	  行参为char *的复合赋值运算符   
      String &StringAdd(const String &str2);  向字符串添加String类型内容
      String &StringAdd(const char *s); 	  向字符串添加char *类型的内容  SADD

    3.int getsize() const; 		获取当前字符串已用空间  SSIZE
    
    4.int getfree() const; 		获取字符串空闲空间  SFREE
    
    5.String &StringClear(); 	清除字符串内容 SCLEAR
    
    6.String &StringSizeClear(size_t pos, size_t len);  以pos开始清除之后len长度的内容 SCLEARS
    
    7.String &StringChange(const char *s);  修改字符串为s
      String &StringChange(const String &str2);  修改字符串为str2  SUPDATE
    
    8.char * StringGetChar();  SCOUT
    
## 日志

  由配置文件控制。
 
##栈
    1.FDB_Stack();   构造函数     STCREAT
    
    2.bool FDB_Stack_empty();  判断栈是否为空   STEMPTY
    
    3.void FDB_Stack_pop();  出栈，从栈中删除   STPOP
    
    4.void FDB_Stack_push(const T &rhs);  向栈添加元素  STPUSH
    
    5.T FDB_Stack_top(); 	读取栈首元素   STTOP
    
    6.unsigned int FDB_Stack_size(); 	返回栈元素个数  STSIZE
    
##队列
    1.FDB_Queue();                构造函数  QUCREAT
    
    2.bool FDB_Queue_empty();     判断对列是否为空  QUEMPTY
    
    3.void FDB_Queue_pop();       出队，从队列中删除  QUPOP
    
    4.T FDB_Queue_front();        读取队首元素  QUFRONT
    
    5.T FDB_Queue_back();         读取队尾元素  QUBACK
    
    6.void FDB_Queue_push(const T &rhs);      向对列添加元素  QUPUSH
    
    7.unsigned int FDB_Queue_size();          返回对列元素个数  QUSIZE