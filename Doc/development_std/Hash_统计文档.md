#FDB_Hash 类的统计文档

##概要
关于哈希表数据结构的接口
 这个文档在于统计以有开发的类，接口说明，帮助开发人员使用其它人开发的类。
##目录

##Hash_node_pseudo 类 

哈希表的结点类：

```
template <typename T>
class Hash_node_pseudo
{
private:
    String key;                 //键值对的键
    T value;                    //键值对的值
    unsigned int hash_num;      //键值对键的hash值
public:
    Hash_node_pseudo() = default; 
    Hash_node_pseudo(const String & Key, const T & data);   //初始化该键值对
    ~Hash_node_pseudo() = default;
    void Hash_set(const String &Key, const T & data);       //向一个键值对写入信息
    void Hash_show();                           //测试时使用的借口，打印键值对的所有信息
    void Set_hash_key(unsigned int a);          //向键值对的hash值写入结果
    String Hash_key();                          //返回键值对的键
    T Hash_value();                             //返回键值对的值
    unsigned int Get_hash_key();                //返回键值对的hash值
};
```


   1.接口：Hash_node_pseudo(const String & Key, const T & data);    
   
     功能：初始化该键值对
   
     参数：相应的键key和值data
   
   2.接口：void Hash_set(const String &Key, const T & data);
   
     功能：向一个键值对写入信息
     
     参数：完成键值对，其中键为key，值为data
     
   3.接口：void Hash_show();
   
     功能：测试函数，打印键值对信息
     
     参数：无参数
     
   4.接口：void Set_hash_key(unsigned int a);          
   
     功能：向键值对的hash值写入结果
     
     参数：参数是该键值对的hash值
     
   5.接口：String Hash_key();                          
   
     功能：返回键值对的键
     
     参数：无参数
   
   6.接口：T Hash_value();                             
   
     功能：返回键值对的值
     
     参数：无参数
   
   7.接口：unsigned int Get_hash_key();                
   
     功能：返回键值对的hash值
     
     参数：无参数
   
   
##Hash_map_pseudo 类   
伪哈希类

```
template <typename T>
class Hash_map_pseudo
{
private:
    std::vector<Hash_node_pseudo<T> > data;     //保存键值对的容器
public:
    Hash_map_pseudo() = default;
    ~Hash_map_pseudo() = default;
    void Hash_pseudo_set(const String&  a, const T& b);     //向容器中添加键为a，值为b的键值对
    void Hash_pseudo_set(Hash_node_pseudo<T> rhs);          //相容器中添加键值对
    void Hash_pseudo_del(const String & rhs);               //在容器中删除指定键的键值对
    void Hash_pseudo_change(const String & a, const T & b); //将键为a的键值对的值修改为b
    //将与rhs键值对中键相等的键值对替换为rhs
    void Hash_pseudo_change(Hash_node_pseudo<T> rhs);       
    bool Hash_pseudo_test(const String & rhs);              //测试容器中是否存在键为rhs的键值对
    T Hash_pseudo_find(const String & rhs);                 //返回键值对中键为rhs的值
    void Hash_pseudo_show();                                //测试函数，打印容器中所有键值对的信息
    int Hash_pseudo_size();                                 //返回容器中保存键值对的数目
    void Hash_pseudo_destory();                             //消除容器
    std::vector<Hash_node_pseudo<T> > Hash_pseudo_data();   //返回保存键值对的容器
};
```
     
   1.接口：void Hash_pseudo_set(const String&  a, const T& b);     
   
     功能：向容器中添加键为a，值为b的键值对
     
     参数：见功能
     
   2.接口：void Hash_pseudo_set(Hash_node_pseudo<T> rhs);
   
     功能：相容器中添加键值对
     
     参数：需要添加的键值对
   
   3.接口：void Hash_pseudo_del(const String & rhs);
   
     功能：在容器中删除指定键的键值对
     
     参数：需要删除的键值对的键
   
   4.接口：void Hash_pseudo_change(const String & a, const T & b);
   
     功能：将键为a的键值对的值修改为b
     
     参数：见功能
   
   5.接口：void Hash_pseudo_change(Hash_node_pseudo<T> rhs);
   
     功能：将容器中与rhs键值对中键相等的键值对替换为rhs
     
     参数：见功能
     
   6.接口：bool Hash_pseudo_test(const String & rhs);
   
     功能：测试容器中是否存在键为rhs的键值对
     
     参数：见功能
   
   7.接口：T Hash_pseudo_find(const String & rhs);
   
     功能：返回键值对中键为rhs的值
     
     参数：见功能
     
   8.接口：void Hash_pseudo_show();
   
     功能：测试函数，打印容器中所有键值对的信息
     
     参数：无参数
     
   9.接口：int Hash_pseudo_size();
   
     功能：返回容器中保存键值对的数目
     
     参数：无参数
     
   10.接口：void Hash_pseudo_destory();
   
     功能：消除容器
     
     参数：无参数
     
   11.接口：std::vector<Hash_node_pseudo<T> > Hash_pseudo_data();
   
     功能：返回保存键值对的容器
     
     参数：无参数
     
     
##Hash_map 类   
哈希表类

```  
template <typename T>
class Hash_map
{
private:
    unsigned long used;         //键值对保存在hash表中的大小
    unsigned long size;         //hash表的大小
    std::vector<std::list<Hash_node_pseudo<T>>> hash;   //hash表的实现
    unsigned long reused;       //键值对保存在rehash表中的大小
    unsigned long resize;       //rehash表的大小
    std::vector<std::list<Hash_node_pseudo<T>>> rehash; //rehash表的实现
    int rehashhidx;             //标志rehash是否使用（-1的代表未使用）
public:
    Hash_map();                 //初始化空哈希表
    Hash_map(Hash_map_pseudo<T> rhs);       //由伪哈希表向哈希表的转换（包括其内键值对的移动）
    
    void Hash_map_add(Hash_node_pseudo<T> rhs);     //向哈希表添加键值对
    void Hash_map_del(Hash_node_pseudo<T> rhs);     //删除哈希表中的键值对rhs
//由hash向rehash渐近式哈希的迁移，包括当hash表迁移完所有后将用rehash代替hash，并将新的rehash置空
    void Hash_map_rehash();                         
    void Hash_map_change(Hash_node_pseudo<T> rhs);  //将与rhs键值对的键相等的键值对替换为rhs
    void Hash_map_destory();                        //清空哈希表，并再次初始化它
    void Hash_map_show();                           //测试函数，打印哈希表的数据
    bool Hash_map_find(Hash_node_pseudo<T> rhs);    //测试rhs键值对是否存在在哈希表中
    T Hash_map_value(String rhs);                   //返回哈希表中键位rhs的键值对的值

    unsigned int GetKey_char(const void *key);      //hash函数
    unsigned int GetKey_int(unsigned int key);      //hash函数
};
``` 


    1.接口：Hash_map();
    
      功能：初始化空哈希表
      
      参数：无参数
      
    2.接口：Hash_map(Hash_map_pseudo<T> rhs);
    
      功能：由伪哈希表向哈希表的转换（包括其内键值对的移动）
      
      参数：需要转换的伪哈希。
     
    3.接口：void Hash_map_add(Hash_node_pseudo<T> rhs);
    
      功能：向哈希表添加键值对
      
      参数：需要添加的键值对
    
    4.接口：void Hash_map_del(Hash_node_pseudo<T> rhs);
    
      功能：删除哈希表中的键值对rhs
      
      参数：需要删除的键值对
      
    5.接口：void Hash_map_rehash();
    
      功能：由hash向rehash渐近式哈希的迁移，包括当hash表迁移完所有后将用rehash代替hash，并将新的rehash置空
      
      参数：无参数
      
    6.接口：void Hash_map_change(Hash_node_pseudo<T> rhs);
    
      功能：将与rhs键值对的键相等的键值对替换为rhs
      
      参数：见功能
      
    7.接口：void Hash_map_destory();
    
      功能：清空哈希表，并再次初始化它
      
      参数：无参数
      
    8.接口：void Hash_map_show();
    
      功能：测试函数，打印哈希表的数据
      
      参数：无参数
      
    9.接口：bool Hash_map_find(Hash_node_pseudo<T> rhs);
    
      功能：测试rhs键值对是否存在在哈希表中
      
      参数：见功能
      
    10.接口：T Hash_map_value(String rhs);
    
      功能：返回哈希表中键位rhs的键值对的值
      
      参数：见功能
      
    11.接口：unsigned int GetKey_char(const void *key);
    
      功能：hash函数
      
      参数：需要进行hash的字符串
      
    12.接口：unsigned int GetKey_int(unsigned int key);
    
      功能：hash函数
      
      参数：需要进行hash的正整数

   
   
   
   
   