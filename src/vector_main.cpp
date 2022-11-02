#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

class CGame
{
public:
    CGame()=default;
    CGame(string s,int price):name(s),price(price){}
    bool operator<(CGame const& that)const
    {
        return price<that.price;
    }
    friend ostream& operator<<(ostream & os,CGame const& gm);
    bool operator==(CGame const& g1)const
    {
        return name==g1.name && price==g1.price;
    }
private:
    string name;
    int price;
};

class CMP
{
public:
    bool operator()(CGame const& g1,CGame const& g2)
    {
        return g1<g2;
    }
};
ostream& operator<<(ostream& os,CGame const& gm)
{
    os<<"name: "<<gm.name<<", price: "<<gm.price<<endl;
    return os;
}
int main()
{
    vector<CGame> vg;
    vg.reserve(10);//1
    vg.push_back(CGame("lilisi",100));
    vg.push_back(CGame("庄园领主",210));
    vg.push_back(CGame("时之歌",150));
    vg.push_back(CGame("湖",130));
    typedef typename vector<CGame>::iterator VIT;
    CMP cmp;
    sort(vg.begin(),vg.end(),cmp);
    VIT it;
    for(it=vg.begin();it!=vg.end();++it)
    {
        cout<<*it;
    }
    cout<<endl;
    VIT eit=find(vg.begin(),vg.end(),CGame("湖",130));
    vg.erase(eit);
    vg.insert(eit,CGame("骑砍2",198));
    sort(vg.begin(),vg.end(),cmp);
    for(it=vg.begin();it!=vg.end();++it)
    {
        cout<<*it;
    }
    cout<<endl;
    return 0;
}