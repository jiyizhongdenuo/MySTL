#include<iostream>
#include<cstring>
using namespace std;
template<class T>
T Sum(T A,T B);
char * Sum(const char * A,const char* B);
int main()
{   
    int A=10,B=20;
    cout<<Sum(A,B);
    cout<<endl<<Sum("ab","cd");
    return 0;
}

template<class T>
T Sum(T A,T B)
{
    cout<<"T"<<endl;
    return A+B;
}

char * Sum(const char * A,const char* B)
{
    cout<<"char *"<<endl;
    char *str=new char[32];
    strcat(str,A);
    strcat(str,B);
    return str;
}