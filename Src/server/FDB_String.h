/*************************************************************************
	> File Name: FDB_string.h
	> Author: 
	> Mail: 
	> Created Time: 2016年03月23日 星期三 08时23分40秒
 ************************************************************************/

#ifndef _FDB_STRING_H
#define _FDB_STRING_H

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cassert>

#define STRING_MAX  1 << 12		//字符串最大长度
#define LEN(n)      (n * 2 + 1)		//初始化时整体长度
#define FREE(n)     (LEN(n) - n)	//预分配长度

#define DEFAULT_NULL 	0		//默认空字符串长度
#define  DEFAULT_SIZE   (1<<7) 		//默认数组长度

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

private:
    int size; 		//字符串已用长度
    int free;		//字符串已经使用长度
    char *str; 		//空闲长度
public:
    String(); 				//无参构造
    String(char *rhs); 			//行参为char* 构造函数
    String(const String &rhs); 		//复制构造函数
    String(String &&rhs) noexcept;
    ~String();  			//析构函数

    //重载运算符
    String & operator=(const String &rhs); 	//赋值运算符
    String & operator=(const char *rhs);    //行参为char* 的赋值运算符
    //String & operaotr=(String&& rhs) noexcept;
    char& operator[](int i);			    //下标运算符
    String& operator+=(const String &rhs); 	//复合赋值运算符
    String& operator+=(const char *rhs); 	//行参为char *的复合赋值运算符

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
    char * StringGetChar();
};

#endif
