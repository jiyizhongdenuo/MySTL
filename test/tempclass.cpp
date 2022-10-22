#include<iostream>

using namespace std;

template<class T,class D>
class Employee
{
public:
    Employee(T A,D B):count(A),cose(B){}
    T Count();
    D Cose();
private:
    T count;
    D cose;
};

template <class T,class D>D Employee<T,D>::Cose()
{
    return cose;
}

template<class T,class D>T Employee<T,D>::Count()
{
    return count;
}

template<class T>class Sum
{
public:
    Sum(T s):sum(s){};
    double RSum();
private:
    T sum;
    static double radix;
};

template<>double Sum<int>::radix=5;

template<>double Sum<int>::RSum(){return radix*sum;} 

template<class T>double Sum<T>::radix=3;

template<class T>
double Sum<T>::RSum() 
{
    return radix*sum.Cose();
}

// template<>class Sum<int>
// {
// public:
// private:
//     int sum;
//     static double radix;
// };

int main()
{
    Employee<int,double> employees(3,10.5);
    cout<<employees.Count()<<endl;
    cout<<employees.Cose()<<endl;
    Sum<Employee<int,double> > sum(employees);
    cout<<sum.RSum()<<endl;
    Sum<int> sum1(5);
    cout<<sum1.RSum()<<endl;
    return 0;
}
