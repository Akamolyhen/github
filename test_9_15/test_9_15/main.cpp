//
//  main.cpp
//  test_9_15
//
//  Created by 赵凡 on 2019/9/15.
//  Copyright © 2019 赵凡. All rights reserved.
//

#include <iostream>
using namespace std;
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

//struct Student
//{
//    void SetStudentInfo(const char* name,const char* gender,int age)
//    {
//        strcpy(_name,name);
//        strcpy(_gender,gender);
//        _age = age;
//    }
//
//    void PrintStudentInfo()
//    {
//        cout<<_name<<" "<<_gender<<" "<<_age<<endl;
//    }
//
//    char _name[20];
//    char _gender[3];
//    int _age;
//};
//
//int main()
//{
//    Student s;
//    s.SetStudentInfo("Perter", "男", 18);
//    s.PrintStudentInfo();
//    return 0;
//}
//
//
//class Person
//{
//public:
//    void PrintPersonInfo();
//private:
//    char _name[20];
//    char _gender[3];
//    int _age;
//};
//
//void Person::PrintPersonInfo()
//{
//    cout<<_name<<" "<<" "<<_age<<endl;
//}


class Date
{
public:
    void Display()
    {
        cout<<_year<<"_"<<_month<<"_"<<_day<<endl;
    }
    
    void SetDate(int year,int month,int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d1,d2;
    d1.SetDate(2018, 5, 1);
    d2.SetDate(2018, 7, 1);
    d1.Display();
    d2.Display();
    return 0;
}
