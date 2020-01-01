//
//  main.cpp
//  test_10_13
//
//  Created by 赵凡 on 2019/10/13.
//  Copyright © 2019 赵凡. All rights reserved.
//

#include <iostream>
using namespace std;

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}


//初始化列表

//class Date
//{
//public:
//    Date(int year,int month,int day)
//    :_year(year)
//    ,_month(month)
//    ,_day(day)
//    {}
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};


//class A
//{
//public:
//    A(int a)
//    :_a(a)
//    {}
//private:
//    int _a;
//};
//
//class B
//{
//public:
//    B(int a,int ref)
//    :_aobj(a)
//    ,_ref(ref)
//    ,_n(10)
//    {}
//private:
//    A _aobj;
//    int& _ref;
//    const int _n;
//};


//class Time
//{
//public:
//    Time(int hour = 0)
//    :_hour(hour)
//    {
//        cout<<"Time()"<<endl;
//    }
//private:
//    int _hour;
//};
//
//class Date
//{
//public:
//    Date(int day)
//    :_day(day)
//    {}
//private:
//    int _day;
//    Time _t;
//};
//
//int main()
//{
//    Date d(1);
//    return 0;
//}


//class Date
//{
//public:
//    Date(int year)
//    :_year(year)
//    {}
//    
//    explicit Date(int year)
//    :_year(year)
//    {}
//    
//private:
//    int _year;
//    int _month;
//    int _day;
//};

class B
{
public:
    B(int b = 0)
    :_b(b)
    {}

    int _b;
};
class A
{
public:
    void print()
    {
        cout<<a<<endl;
        cout<<b._b<<endl;
        //cout<<p<<endl;
    }
private:
    int a = 10;
    B b = 20;
    int* p = (int*)malloc(4);
    static int n;
};


int A::n = 10;

int main()
{
    A a;
    a.print();
    return 0;
}


//int main()
//{
//    int* p = (int*)malloc(4);
//    cout<<p<<endl;
//    return 0;
//}


