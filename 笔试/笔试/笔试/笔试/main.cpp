//
//  main.cpp
//  笔试
//
//  Created by 恶龙咆哮 on 2020/8/30.
//  Copyright © 2020 秦伟钦. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    char* str1 = "01234567891";
    cout<<strlen(str1)<<endl;
    return 0;
}
void test2()
{
 char string[10], str1[10];
 int i;
 for(i=0; i<10; i++)
 {
 str1[i]  = 'a';
 }
    str1[9]='\0';
strcpy( string, str1 );
}
