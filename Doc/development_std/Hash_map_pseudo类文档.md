#类的开发文档编写规则

##类的名称（编号）

   FDB_Hash_map.h
   
##类的声明与作用
   
   伪哈希数据结构的类
   
###类开发的必要性，唯一性
  
  
  
###类中各函数的复杂度，可能瓶颈
        
        在调用Hash_map_find成员函数之前必须先调用Hash_map_test成员函数测试这个key是否在data中
 
    void Hash_pseudo_set(const String&  a, const T& b);  O（1）   
    
    void Hash_pseudo_set(Hash_node_pseudo<T> rhs);O（1）
    
    void Hash_pseudo_del(const String & rhs);O（N）
    
    void Hash_pseudo_change(const String & a, const T & b); O（N ）
    
    void Hash_pseudo_change(Hash_node_pseudo<T> rhs);  O（N）
         
    bool Hash_pseudo_test(const String & rhs);O（N）
    
    T Hash_pseudo_find(const String & rhs);O（N）
    
    void Hash_pseudo_show(); O（N）
    
    int Hash_pseudo_size();O（1）
  
    void Hash_pseudo_destory(); O（1）
    
    std::vector<Hash_node_pseudo<T> > Hash_pseudo_data();O（1）
 
##类的声明与定义

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

###类成员函数接口说明
   
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
   
###审阅人批覆