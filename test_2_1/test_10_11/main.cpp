//
//  main.cpp
//  test_10_11
//
//  Created by 赵凡 on 2019/10/11.
//  Copyright © 2019 赵凡. All rights reserved.
//

#include <iostream>
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

using namespace std;

//class String
//{
//public:
//    String(const char* str = "jack")
//    {
//        _str = (char*)malloc(strlen(str) + 1);
//        strcpy(_str,str);
//    }
//
//    ~String()
//    {
//        cout<<"~String()"<<endl;
//        free(_str);
//    }
//private:
//    char* _str;
//};
//
//class Person
//{
//public:
//private:
//    String _name;
//    int _age;
//};
//
//int main()
//{
//    Person p;
//    return 0;
//}


//class Date
//{
//public:
//    Date(int year = 1900,int month = 1,int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//    void Display()
//    {
//        cout<<_year<<" "<<_month<<" "<<_day<<endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    d1.Display();
//    Date d2(d1);
//    d2.Display();
//    return 0;
//}


//class String
//{
//public:
//    String(const char* str = "jack")
//    {
//        _str = (char*)malloc(strlen(str) + 1);
//        strcpy(_str,str);
//    }
//
//    ~String()
//    {
//        cout<<"~String()"<<endl;
//        free(_str);
//    }
//
//
//    void Display()
//    {
//        cout<<_str<<endl;
//    }
//
//private:
//    char* _str;
//};
//
//
//int main()
//{
//    String s1("hello");
//    s1.Display();
////    String s2(s1);
////    s2.Display();
//    return 0;
//}

//class Date
//{
//public:
//    Date(int year = 1900,int month = 1,int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//
//    //bool operator==(Date* this,const Date& d2)
//    //这里的做坐操作数是this指向的调用函数的对象
//    bool operator==(const Date& d2)
//    {
//        return _year == d2._year
//            && _month == d2._month
//            && _day == d2._day;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};


//bool operator==(const Date& d1,const Date& d2)
//{
//    return d1._year == d2._year
//        && d1._month == d2._month
//        && d1._day == d2._day;
//}

//void Test()
//{
//    Date d1(2018,9,26);
//    Date d2(2018,9,27);
//    cout<<(d1 == d2)<<endl;
//}
//
//int main()
//{
//    Test();
//    return 0;
//}


//class Date
//{
//public:
//    Date(int year = 1900,int month = 1,int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//
//        void Display()
//        {
//            cout<<_year<<" "<<_month<<" "<<_day<<endl;
//        }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d1;
//    Date d2(2018,10,1);
//    d1.Display();
//    d2.Display();
//    //d1调用编译器生成的operator=完成拷贝，d2和d1的值是一样的
//    d1 = d2;
//    d1.Display();
//    d2.Display();
//    return 0;
//}


//class String
//{
//public:
//    String(const char* str = "jack")
//    {
//        _str = (char*)malloc(strlen(str) + 1);
//        strcpy(_str,str);
//    }
//
//    ~String()
//    {
//        cout<<"~String()"<<endl;
//        free(_str);
//    }
//
//private:
//    char* _str;
//};
//
//int main()
//{
//    String s1("hello");
//    String s2("world");
//
//    s1 = s2;
//    return 0;
//}


class Date
{
public:
    void Display()
    {
        cout<<"Display()"<<endl;
        cout<<"year:"<<_year<<endl;
        cout<<"month:"<<_month<<endl;
        cout<<"day:"<<_day<<endl;
    }
    
    void Display() const
    {
        cout<<"Display() const"<<endl;
        cout<<"year:"<<_year<<endl;
        cout<<"month:"<<_month<<endl;
        cout<<"day:"<<_day<<endl;
    }
    
private:
    int _year;
    int _month;
    int _day;
};


int main()
{
    Date d1;
    d1.Display();
    Date d2;
    d2.Display();
    return 0;
}
