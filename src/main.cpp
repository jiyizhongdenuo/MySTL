#include<iostream>
#include"MyListT.h"
using namespace std;

ostream& operator<<(ostream & os, MyListT<int>& l)
{
    for(MyListT<int>::node* pnode=l.m_head;pnode;pnode=pnode->m_next)
    {
        os<<pnode->m_data<<"\t";
    }
    return os;
}

void printl(string const& str,MyListT<int>& ls)
{
    cout<<str<<endl;
    typedef  typename MyListT<int>::iterator IT;//typename告诉编译器这是个类而不是iterator成员
    for(IT it=ls.begin();it!=ls.end();++it)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main()
{
    MyListT<int> ls;
    for(int i=0;i<5;i++)
    {
        ls.push_back(i*i);
    }
    for(int j=0;j<5;j++)
    {
        ls.push_front(j%3);
    }
    // cout<<ls<<endl;
    printl("删除头尾节点前：",ls);
    ls.pop_back();
    ls.pop_front();
    printl("删除头尾节点后：",ls);
    ls.insert(++ls.begin(),66);
    ls.erase(ls.begin());//end()为null节点。
    printl("insert之后",ls);
    return 0;
}

// MyStringTest;;
// int main()
// {
//     cout<<"abcd";
//     CMyString str1(5,'a');
//     CMyString str2("abcd");
//     std::cout<<str1.CStr()<<endl<<str2.CStr();
//     CMyString str3("abc",5);
//     cout<<endl<<str3.CStr()<<endl;
//     // CMyString str4(str3,1,3);
//     system("pause");
//     return 0;
// }