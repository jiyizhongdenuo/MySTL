#include"MyString.h"
#include<iostream>

CMyString::CMyString()
{
    m_str=new char('\0');
}

CMyString::~CMyString()
{
    std::cout<<"delete m_str!";
    delete []m_str; 
}

CMyString::CMyString(size_t length,char ch)
{
    m_str=new char[length+1];
    for(size_t i=0;i<length;i++)
    {
        m_str[i]=ch;
    }
    m_str[length]='\0';
}

CMyString::CMyString(const char *ch)
{
    int count=0;
    for(;'\0'!=*ch;ch++)count++;
    m_str=new char[count+1];
    for(int i=0;i<count+1;i++)
    {
        m_str[i]=ch[i];
    }
}

CMyString::CMyString(const char * ch,size_t length)
{
    if(nullptr==ch || length<=0)return ;
    m_str=new char[length+1];
    int i;
    for(i=0;i<length&&'\0'!=ch[i];i++)
    {
        m_str[i]=ch[i];
    }
    m_str[i+1]='\0';
}

const char *CMyString::CStr() const
{
    return m_str;
}

CMyString::CMyString(CMyString str, size_t start,size_t end)
{
    m_str=new char[end-start+1];
    size_t i;
    for(i=0;i<end-start;i++)
    {
        m_str[i]=str.CStr()[i+start];
    }
    m_str[i+1]='\0';
}



