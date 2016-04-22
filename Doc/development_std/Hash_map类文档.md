#类的开发文档编写规则

##类的名称（编号）
  
    FDB_Hash_map.h
    
##类的声明与作用
   
   哈希数据结构的真正实现的类
   
###类开发的必要性，唯一性

   向对于伪哈希，真正的哈希在数据量大的情况下可以更快的进行操作

###类中各函数的复杂度，可能瓶颈
  
    Hash_map();O（1）
    
    Hash_map(Hash_map_pseudo<T> rhs);O（N）
    
    void Hash_map_add(Hash_node_pseudo<T> rhs); O（1）
    
    void Hash_map_del(Hash_node_pseudo<T> rhs);O（1）
    
    void Hash_map_rehash();  O（N）
                           
    void Hash_map_change(Hash_node_pseudo<T> rhs);  O（1）
    
    void Hash_map_destory();O（1）
    
    void Hash_map_show();O（N）
    
    bool Hash_map_find(Hash_node_pseudo<T> rhs);O（1）
    
    T Hash_map_value(String rhs); O（1）
  
##类的声明与定义
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
###类成员函数接口说明
   
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
   
###审阅人批覆