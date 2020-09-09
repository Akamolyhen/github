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
/*#include<iostream>
using namespace std;
long long c[105][105];//多申请存储空间
const int mod=1000000007;
/// 利用杨辉三角
void init()
{
    c[0][0]=1;
    for(int i=1;i<=100;i++)
    {
        c[i][0]=1;
        for(int j=1;j<100;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
}

int main()
{
    init();
    int i,j,k,a,x,b,y;
    long long sum=0;
   while( cin>>k>>a>>x>>b>>y)
   {if(a!=b)
        {
            for(i=0;i<=x;i++)
            for(j=0;j<=y;j++)
                {
                    if((i*a+j*b)>k)
                        break;
                    if((i*a+j*b)==k)
                        sum+=c[x][i]*c[y][j];
                }
          cout<<sum<<endl;
          return 0;
        }
   }
         
   
}*/


//安排机器
/*#include<iostream>
using namespace std;
#define LL long long
const int maxn=1e5+10;
struct node{
    int x,y;
}e[maxn],f[maxn];
int cnt[105];//记录可使用的任务难度
int cmp(node a,node b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>e[i].x>>e[i].y;
    for(int j=0;j<m;j++)
        cin>>f[j].x>>f[j].y;
    sort(e,e+n,cmp);
    sort(f,f+m,cmp);
    int num=0;
    LL ans=0;
    memset(cnt,0,sizeof(cnt));
    int i,j,k;//i：任务数，j：机器数，k：难度等级
    for(i=0,j=0;i<m;i++)
    {
        while(j<n&&e[j].x>=f[i].x)//判断可用机器和所用时间
        {
            cnt[e[j].y]++;//把该机器难度记录
            j++;
        }
        for(k=f[i].y;k<=100;k++)//将此时任务的难度系数给k，看cnt这个数组所在的难度里有无机器满足
        {
            if(cnt[k])
            {
                num++;
                cnt[k]--;
                ans+=200*f[i].x+3*f[i].y;
                break;
            }
        }
    }
    cout<<num<<' '<<ans<<endl;
    return 0;
}
*/






