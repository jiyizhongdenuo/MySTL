#include<iostream>

using namespace std;
#define Max(T) T max_##T(T x,T y){return x>y?x:y;}

Max(int);
Max(double);
Max(string);

#define max(T) max_##T
int main()
{
    int x=10,y=20;
    double dx=10.0,dy=20.0;
    cout<<max_int(x,y);
    cout<<max(double)(dx,dy);


    return 0;
}