#类的开发文档编写规则

##类的名称（编号）

  FDB_Hash_node.h
  
##类的声明与作用
   
   哈希数据结构的结点类；
   
   用于保存哈希的每一个结点（键值对）；
   
###类开发的必要性，唯一性

  和已存在的功能类似的类相比较
  
###类中各函数的复杂度，可能瓶颈

  Hash_node_pseudo(const String & Key, const T & data);         O（1）
   
  void Hash_set(const String &Key, const T & data);             O（1）
  
  void Hash_show();                                             O（1）
  
  void Set_hash_key(unsigned int a);                            O（1）
  
  String Hash_key();                                            O（1）
  
  T Hash_value();                                               O（1）
  
  unsigned int Get_hash_key();                                  O（1）
  
##类的声明与定义
  贴出类的声明，相应注释
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
###类成员函数接口说明
   
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

###审阅人批覆