#include<iostream>
#include<deque>
#include<cstdio>
#include<algorithm>

using namespace std;

class Savers
{
public:
    Savers()=default;
    Savers(string const& s,unsigned int n):name(s),num(n){cout<<name<<"位置: "<<this<<endl;}
    ~Savers(){cout<<"delete: "<<name<<"位置"<<this<<endl;}
    bool operator==(Savers const& that)const
    {
        return name==that.name && num==that.num;
    }
    bool operator<(Savers const& that)const
    {
        return num<that.num;
    }
    friend ostream& operator<<(ostream & os,Savers const& ss); 
    friend class CMP;
private:
    string name;
    unsigned int num;
};

ostream& operator<<(ostream &os, Savers const& ss)
{
    cout<<ss.name<<", cost: "<<ss.num<<endl;
    return os;
}

class CMP
{
public:
    bool operator()(Savers const&a,Savers const& b)
    {
        return a.num>b.num;
    }
};
int main()
{
    deque<Savers> ds;
    // ds.resize(10);
    ds.push_front(Savers("nuo",20));
    ds.push_front(Savers("aililsi",66));
    ds.push_back(Savers("an",16));
    ds.push_back(Savers("tansanda",11));
    // getchar();
    typedef typename deque<Savers>::iterator DIT;
    DIT it;
    for(it=ds.begin();it!=ds.end();++it)
    {
        cout<<*it;
    }
    cout<<endl;
    DIT fit=find(ds.begin(),ds.end(),Savers("an",16));
    *fit=Savers("keleya",80);
    ds.insert(fit,Savers("AI",99));
    for(it=ds.begin();it!=ds.end();++it)
    {
        cout<<*it;
    }
    CMP cmp;
    sort(ds.begin(),ds.end(),cmp);
    
    cout<<"sort:"<<endl;
    for(it=ds.begin();it!=ds.end();++it)
    {
        cout<<*it;
    }
    return 0;
}