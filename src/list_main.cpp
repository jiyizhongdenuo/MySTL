#include<iostream>
#include<list>

typedef typename std::list<int>::iterator LIT;
using namespace std;
void print(std::string const& s,std::list<int>& ls)
{
    cout<<s<<endl;
    for(LIT it=ls.begin(); it!=ls.end();++it)
    {
        cout<<*it<<"\t";
    }
    cout<<endl;
}

class CMP
{
public:
    bool operator()(int const& a, int const& b)
    {
        return a>b;
    }
};

int main()
{
    using namespace std;
    list<int> li;
    for(int i=0;i<5;i++)
    {
        li.push_back(i);
        li.push_front(i*i);
    }
    print("节点内容",li);
    CMP cmp;
    li.sort(cmp);
    li.unique();//1
    print("unique 之后",li);
    list<int> lsi;
    lsi.push_back(555);
    lsi.push_front(666);
    lsi.push_front(333);
    lsi.push_front(1);    
    print("lsi:",lsi);
    li.splice(li.begin(),lsi,lsi.begin(),--lsi.end());//2
    print("splice:",li);
    print("splice:",lsi);
    return 0;
}