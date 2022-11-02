#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    stack<int,deque<int> > si;
    si.push(33);
    si.push(44);
    si.push(55);
    si.push(66);
    while(!si.empty())
    {
        cout<<si.top()<<"\t";
        si.pop();
    }
    cout<<endl;
    queue<int,deque<int> > qi;
    qi.push(1);
    qi.push(2);
    qi.push(3);
    qi.push(4);
    while(!qi.empty())
    {
        cout<<qi.front()<<"\t";
        qi.pop();
    }
    return 0;
}