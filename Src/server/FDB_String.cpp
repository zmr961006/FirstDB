/*************************************************************************
	> File Name: FDB_string.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年03月23日 星期三 13时58分01秒
 ************************************************************************/

#include"./FDB_String.h"

String::String()
{
    size = DEFAULT_NULL;
    free = FREE(size);
    str = new char[LEN(size)];
    str[0] = '\0';
}

String::String(char *rhs)
{
    size = std::strlen(rhs);
    free = FREE(size);
    str = new char[LEN(size)];
    std::memcpy(str, rhs, size + 1);
}

String::String(const String &rhs)
{  
    size = rhs.size;
    free = FREE(size);
    str = new char[LEN(size)];
    std::memcpy(str, rhs.str, size + 1);
}

String::~String()
{
    delete [] str;
}

String& String::operator=(const String &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    
    if ( (size + free) <= rhs.size )
    {
        delete [] str;
        
        str = new char[LEN(rhs.size)];
        free = FREE(rhs.size);
	size = rhs.size;
    	std::memcpy(str, rhs.str, size + 1);
    }
    else 
    {
        free = size + free - rhs.size;
	size = rhs.size;
    	std::memcpy(str, rhs.str, size + 1);
    }
    
    
    return *this;
}

String& String::operator=(const char *rhs)
{
    int rhs_size = std::strlen(rhs);
    
    if ( (size + free) <= rhs_size && rhs_size << STRING_MAX)
    {
        delete [] str;
        
        str = new char[LEN(rhs_size)];
        free = FREE(rhs_size);
	size = rhs_size;
    	std::memcpy(str, rhs, size + 1);
    }
    else if ( rhs_size  < (size + free) )
    {
        free = (size + free) - rhs_size;
	size = rhs_size;
   	std::memcpy(str, rhs, size + 1);
    }
    
    
    return *this;
}

char& String::operator[](int i)
{
    return str[i];
}

bool operator<(const String &lhs, const String &rhs)
{
    return (strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const String &lhs, const String &rhs)
{
    return (strcmp(lhs.str, rhs.str) > 0);
}

bool operator==(const String &lhs, const String &rhs)
{
    return (strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream &os, const String &rhs)
{
    os << rhs.str;
    
    return os;
}

std::istream& operator>>(std::istream &is, String &rhs)
{
    char temp[DEFAULT_SIZE];
    
    if (is >> temp)
    {
        int is_size = std::strlen(temp);
        if ( (rhs.size + rhs.free) <= is_size)
        {
            delete [] rhs.str;
            
            rhs.str = new char[LEN(is_size)];
            rhs.free = FREE(is_size);
        }
        else 
        {
            rhs.free = (rhs.size + rhs.free) - is_size;
        }
        rhs.size = is_size;
        std::memcpy(rhs.str, temp, rhs.size + 1);
    }
    
    return is;
}

String operator+(const String &lhs, const String &rhs)
{
    String ret = lhs;
    ret += rhs;
    
    return ret;
}

String operator+(const String &lhs, const char *rhs)
{
    String ret = lhs;
    ret += rhs;
    
    return ret;
}

String& String::operator+=(const String &rhs)
{
    int len = rhs.getsize();
    
    if (len < free) 
    {
        std::memcpy(str + size, rhs.str, len + 1);
        size += len;
        free -= len;
    }
    else if (len <= STRING_MAX && len >= free)
    {
        char temp[size + 1];
        memcpy(temp, str, size + 1);
        delete [] str;
        str = new char[LEN(size)];
        std::memcpy(str, temp, size + 1);
        std::memcpy(str + size, rhs.str, len + 1);
        size += len;
        free = FREE(size);
    }
    return *this;
}

String& String::operator+=(const char *rhs)
{
    int len = std::strlen(rhs);
    if (len < free) 
    {
        std::memcpy(str + size, rhs, len + 1);
        size += len;
        free -= len;
    }
    else if (len <= STRING_MAX && len >= free)
    {
        char temp[size + 1];
        std::memcpy(temp, str, size + 1);
        delete [] str;
        str = new char[LEN(size)];
        std::memcpy(str, temp, size + 1);
        std::memcpy(str + size, rhs, len + 1);
        size = size + len;
	    free = FREE(size);
    }
    return *this;
}

int String::getsize() const
{
    return size;
}

int String::getfree() const
{
    return free;
}

void String::Print()
{
    std::cout << str << std::endl;
}

String& String::StringAdd(const String &str2)
{
    *this += str2;
    return *this;
}

String& String::StringAdd(const char *s)
{
    *this += s;
    return *this;
}

String& String::StringClear()
{
    memset(str, 0, size + free);
    free += size;
    size = 0;

    return *this;
}

String& String::StringSizeClear(size_t pos, size_t len)
{
    if ((pos > size) || (pos + len > size))
    {
        return *this;
    }
    memcpy(str + pos, str + pos + len, len);
    str[size - len] = 0;
    size -= len;
    free += len;

    return *this;
}

String& String::StringChange(const char *s)
{
    *this = s;
    return *this;
}

String& String::StringChange(const String &st)
{
    *this = st;
    return *this;
}
