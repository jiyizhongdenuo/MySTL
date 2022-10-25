#ifndef MYStRING
#define MYSTRING
#include<iostream>

class CMyString
{
public:
    CMyString();
    CMyString(size_t length,char ch);
    CMyString(const char *ch);
    ~CMyString();
    const char * CStr() const;
    CMyString(const char * ch,size_t length);
    CMyString(CMyString str, size_t start,size_t end);
    CMyString(const CMyString& str);

private:
    char * m_str;
};

#endif