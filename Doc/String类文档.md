##类的名称（编号）

FDB_String.h
FDB_String.h

##类的声明与作用

FDB中的字符串类。

##类开发的必要性，唯一性

因为string预分配与SDS上比较有些不足，所以重新封装了自己的字符串类String。SDS在初始化分配空间时便会对已有空间进行预分配，而c++中string类只会在超出其空间之后才会进行预分配，这将降低了其本身效率。

已有文档，见compare_string_SDS.md

##类中各函数的复杂度，可能瓶颈

new的使用仍有瓶颈。
且存在new的遗留问题。


##类的声明与定义

```
class String
{
    //重载部分运算符
    //重载 '>','<','==','!='关系运算符
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    //重载输入输出运算符
    friend std::ostream& operator<<(std::ostream &os, const String &rhs);
    friend std::istream& operator>>(std::istream &is, String &rhs);
    //重载相加运算符
    friend String operator+(const String &lhs, const String &rhs);
    friend String operator+(const String &lhs, const char *rhs);

    
    //修改人：胡兴菊  日期：2016.3.26  修改内容：size 和 free 的注释 
private:
    int size; 		//字符串已经使用长度  
    int free;		//数组中空闲长度
    char *str;
public:
    String(); 				      //无参构造
    String(char *rhs); 			  //形参为char* 构造函数
    String(const String &rhs); 	  //复制构造函数
    ~String();  			      //析构函数

    //重载运算符
    String & operator=(const String &rhs); 	//赋值运算符
    String & operator=(const char *rhs); 	//形参为char* 的赋值运算符
    char& operator[](int i);			    //下标运算符
    String& operator+=(const String &rhs); 	//复合赋值运算符
    String& operator+=(const char *rhs); 	//形参为char *的复合赋值运算符

    //接口函数
    int getsize() const; 				//获取当前字符串已用空间
    int getfree() const; 				//获取字符串空闲空间
    void Print(); 					//打印字符串
    String &StringAdd(const String &str2); 		//向字符串添加String类型内容
    String &StringAdd(const char *s); 			//向字符串添加char *类型的内容
    String &StringClear(); 				//清除字符串内容
    String &StringSizeClear(size_t pos, size_t len); 	//以pos开始清除之后len长度的内容
    String &StringChange(const char *s); 		//修改字符串为s
    String &StringChange(const String &str2); 		//修改字符串为str2
};
```

##类成员函数接口说明

####友元函数：
    1.friend bool operator<(const String &lhs, const String &rhs);
        以lhs对象和rhs对象中的str成员比较大小。若lhs大于rhs则返回ture，否则返回false。O（N）；
    2.friend bool operator>(const String &lhs, const String &rhs);
        以lhs对象和rhs对象中的str成员比较大小。若lhs小于rhs则返回ture，否则返回false。O（N）；
    3.friend bool operator==(const String &lhs, const String &rhs);
        判断lhs对象和rhs对象中的str成员相等。若相等返回ture，否则返回false。O（N）；
    4.friend bool operator!=(const String &lhs, const String &rhs);
        判断lhs对象和rhs对象中的str成员相等。若不相等返回ture，否则返回false。O（N）；
    5.friend std::ostream& operator<<(std::ostream &os, const String &rhs);
        将rhs对象中str对象打印出来。
    6.friend std::istream& operator>>(std::istream &is, String &rhs);
        将is流内的数据写入rhs对象内。
    7.friend String operator+(const String &lhs, const String &rhs);
        将lhs对象和rhs对象向加，返回向加后的结果。O（N）；
    8.friend String operator+(const String &lhs, const char *rhs);
        将lhs对象和rhs数组向加，返回向加后的结果。O（N）；
####成员函数：
    1.int getsize() const; 		
        获取当前字符串已用空间，无参 O（1）；
    2.int getfree() const; 	
        获取字符串空闲空间，无参 O（1）；
    3.void Print(); 
        打印字符串，无参 
    4.String &StringAdd(const String &str2); 
        向字符串添加String类型内容。参数str2为需要添加的String类字符串。返回添加后的字符串。 O（N）；
    5.String &StringAdd(const char *s); 
        向字符串添加char *类型的内容.参数s为需要添加的char *类型字符串。返回添加后的字符串。 O（N）；
    6.String &StringClear(); 				
        清除字符串内容，无参，返回清除后的字符串。O（1）；
    7.String &StringSizeClear(size_t pos, size_t len);
        以pos开始清除之后len长度的内容，参数以说明，返回清除后的字符串。O（N）；
    8.String &StringChange(const char *s); 
        修改字符串为s。参数s为代替原字符串的char*类型字符串。返回改变后的字符串。O（N）；
    9.String &StringChange(const String &str2); 
        修改字符串为str2。参数str为代替原字符串的String类类型字符串。返回改变后的字符串。O（N）；
    10.String & operator=(const String &rhs); 	
        赋值运算符。将rhs对象赋值给this对象。返回this对象。O（N）；
    11.String & operator=(const char *rhs); 	
        形参为char* 的赋值运算符。将rhs数组赋值给this对象。返回this对象。 O（N）；
    12.char& operator[](int i);			    
        下标运算符。获取this对象中str成员下标为i的引用。O（1）；
    13.String& operator+=(const String &rhs);
        复合赋值运算符。将rhs对象与this对象相加并赋值给this对象。O（N）；
    14.String& operator+=(const char *rhs); 	
        形参为char *的复合赋值运算符。将rhs数组与this对象相加并赋值给this对象。O（N）；

       


##审阅人批复：

第一次审阅结果：整体结构清晰，考虑相对周全。主要有一下两点不足，望加以修整：

1.需对函数复杂度详尽说明
2.开发必要性、唯一性文档需要补充修整。主要包括自己构建string类的目的，
以及自己构建的string类和c++的string类的区别。


审阅人：胡兴菊     审阅日期：2016.3.26

对本次审阅问题以作出修改。

修改人：王瑞欣     修改日期：2016.3.27

