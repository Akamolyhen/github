//
//  main.cpp
//  笔试
//
//  Created by 恶龙咆哮 on 2020/8/30.
//  Copyright © 2020 秦伟钦. All rights reserved.
//

/*#include <iostream>
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
*/

/*#include<iostream>
#include<string>
using namespace std;
const int N=1005;
int main()
{
    string s;
    cin>>s;
    int index[26]={0};
    for(int i=0;i<s.size();i++)
    {
        index[s[i]-'A']=max(index[s[i]-'A'],i);
    }
    int st=-1;
    int maxx=0;
    int vis[26]={0};
    for(int i=0;i<s.size();i++)
    {
        if(!vis[s[i]-'A'])
        {
            vis[s[i]-'A']=1;
            maxx=max(maxx,index[s[i]-'A']);
        }
        if(i>=maxx)
        {
            cout<<i-st<<"";
            st=i;
        }
        cout<<endl;
        return 0;
    }
}
*/

//小Q的歌单
#include<iostream>
using namespace std;
long long c[105][105];

