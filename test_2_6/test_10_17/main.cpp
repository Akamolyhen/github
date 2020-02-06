//
//  main.cpp
//  test_10_17
//
//  Created by 赵凡 on 2019/10/17.
//  Copyright © 2019 赵凡. All rights reserved.
//

#include <iostream>
using namespace std;
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

//class Date
//{
//public:
//    Date(int year,int month,int day)
//    :_year(year)
//    ,_month(month)
//    ,_day(day)
//    {}
//
//    ostream& operator<<(ostream& _cout)
//    {
//        _cout<<d._year<<"_"<<d._month<<"_"<<d._day;
//        return _cout;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    Date d(2017,12,24);
//    d<<cout;
//    return 0;
//}


//class Date
//{
//    friend ostream& operator<<(ostream& _cout,const Date& d);
//    friend istream& operator>>(istream& _cin,const Date& d);
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
//
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//    _cout<<d._year<<"_"<<d._month<<"_"<<d._day;
//    return _cout;
//}
//
//istream& operator>>(istream& _cin,const Date& d)
//{
//    _cin>>d._year;
//    _cin>>d._month;
//    _cin>>d._day;
//    return _cin;
//}
//
//int mian()
//{
//    Date d;
//    cin>>d;
//    cout<<d<<endl;
//    return 0;
//}


class Date;
class Time
{
    friend class Date;
public:
    Time(int hour = 0,int minute = 0,int second = 0)
    :_hour(hour)
    ,_minute(minute)
    ,_second(second)
    {}
    
private:
    int _hour;
    int _minute;
    int _second;
};

class Date
{
public:
    Date(int year = 1900,int month = 1,int day = 1)
    :_year(year)
    ,_month(month)
    ,_day(day)
    {}
    
    void SetTimeOfDate(int hour,int minute,int second)
    {
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }
    
    void ShowDateTime()
    {
        cout<<_year<<"_"<<_month<<"_"<<_day<<"  "<<_t._hour<<":"<<_t._minute
        <<":"<<_t._second<<endl;
    }
    
private:
    int _year;
    int _month;
    int _day;
    Time _t;
};

int main()
{
    Date T;
    T.SetTimeOfDate(12,12,12);
    T.ShowDateTime();
    return 0;
}

