//
//  main.cpp
//  test_10__10
//
//  Created by 赵凡 on 2019/10/10.
//  Copyright © 2019 赵凡. All rights reserved.
//

#include <iostream>
#include <string.h>
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

using namespace std;

class String
{
public:
    String(const char* str = "jack")
    {
        _str = (char*)malloc(strlen(str) + 1);
        strcpy(_str,str);
    }
    
    ~String()
    {
        cout<<"~String()"<<endl;
        free(_str);
    }
    
private:
    char* _str;
};

class Person
{
private:
    String _name;
    int _age;
};


int main()
{
    cout<<"hello world!"<<endl;
    Person p;
    return 0;
}
