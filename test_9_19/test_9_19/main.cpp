//
//  main.cpp
//  test_9_19
//
//  Created by 赵凡 on 2019/9/19.
//  Copyright © 2019 赵凡. All rights reserved.
//

#include <iostream>

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

using namespace std;

//class A
//{
//public:
//    void PrintA()
//    {
//        cout<<_a<<endl;
//    }
//
//    void Show()
//    {
//        cout<<"Show()"<<endl;
//    }
//private:
//    int _a;
//};
//
//int main()
//{
//    A* p = NULL;
//    p->PrintA();
//    p->Show();
//    return 0;
//}

//class Date
//{
//public:
//    void SetDate(int year,int month,int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//    void Display()
//    {
//        cout << _year << "_" << _month << "_" << _day << endl;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1,d2;
//    d1.SetDate(2018, 5, 1);
//    d1.Display();
//
//    d2.SetDate(2018, 7, 1);
//    d2.Display();
//
//    return 0;
//}

//class Date
//{
//public:
//
//    //无参构造函数
//    Date()
//    {}
//
//    Date(int year,int month,int day)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};

class Date
{
public:
//    Date()
//    {
//        _year = 1900;
//        _month = 1;
//        _day = 1;
//    }
    
    Date(int year = 1900,int month = 1,int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void Display()
    {
        cout << _year << "_" << _month << "_" << _day << endl;
    }
    private:
    int _year;
    int _month;
    int _day;
};

void TestDate1()
{
    Date d;
    d.Display();
}

//void TestDate()
//{
//    Date d1;//调用无参构造函数
//    Date d2;//调用带参构造函数
//}

int main()
{
    TestDate1();
    return 0;
}
