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


/*
//贪吃的小Q
#include<iostream>
using namespace std;
int main()
{
    int n,m,temp,now,mid;//temp:现在所剩的巧克力 now:每天吃的巧克力
    bool ok;
    cin>>n>>m;
    int left=1,right=m;
    while(left!=right)
    {
        ok=true;
        mid=(left+right+1)/2;//二分法
        temp=m;
        now=mid;
        for(int j=0;j<n;j++)
        {
            if(temp<now)
            {
                ok=false;
                break;
            }
 
            temp-=now;
            now=(now+1)/2;
        }
 
        if(ok)
        {
            left=mid;
        }
        else
            right=mid-1;
        
    }
    cout<<left<<endl;
    return 0;
}
*/
/*
//纸牌游戏
#include<iostream>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int n;
int cmp(int x,int y)
{
    return x>y;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            ans+=a[i];
        else
            ans-=a[i];
    }
    cout<<ans<<endl;
    return 0;
}


*/


//求幂
/*
 对于每一个数，分两种情况：
 1.a==c，这种情况共有n*n (对应1)+n*(n-1) (对应2-n)种情况，就是a,c底数为1时，有n*n种情况；a==c且不等于1时有n-1种（2～n），bd相等的情况有n种（1～n）。
2.a != c, 遍历左右值即可，对于一对a,c有n / (x和y中的较大值/ (x和y的公约数)) * 2种情况
 a^b=c^d----->(i^x)^b = (i^y)^d
 遍历i，且i^x<=n、j^y<=n,求出x和y的范围，除去底数相同的情况，i*i必定小于n
 遍历x和y，取出x和y的最大公约数放到底数做i的指数，(i^m)^n1*b = (i^m)^n2*d
 转换成求n1*b==n2*d 有多少种情况，
 x和y的最大值除以b/d使得等式成立，n1>n2，b、d<n
 所以构造d为n1的倍数即可，总的倍数有n/n1个。同时等式两边可以对调，因此*2
*/
/*#include<iostream>
#include<set>
using namespace std;
int MOD = 1000000000 + 7;
/// 返回最小公约数
int gcd(int a,int b){
    return (a % b == 0) ? b : gcd(b,a%b);
}
int main() {
    int n;
    cin>>n;
    //int会越界，且还需要强制类型转换
    long long ans =(long long) n*(n*2-1) % MOD;//a==c
    set<int> s;
    //遍历i,因为去除了底数相同的情况,所以底数不等的情况下：底数必定大于1，次方必定大于1——>底数小于n的开方
    for (int i = 2; i*i <= n; i++){
        if (s.find(i)!=s.end()) continue;//在s中找i这个数，s.find() 如果没找到返回s.end()
        int tmp = i;
        int cnt = 0;
        //满足条件的底数，同时求x和y的范围
        while(tmp <= n) {
            s.insert(tmp);
            tmp = tmp * i;
            cnt++;
        }
        //相同的公约数，放到下面，反正不会大于n//n / (x和y中的较大值/ (x和y的公约数)) * 2
        for (int k = 1; k <= cnt; k++) {
            for (int j = k + 1; j <= cnt; j++) {
                ans =(ans+(n / (j / gcd(k, j) ) * (long)2 )) % MOD;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/


//整除
#include<iostream>
using namespace std;
const int maxn=1e5+5;
int tmp[maxn];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k=i;
        for(int j=2;j*j<=n;j++){
            int s=0;
            while(k%j==0){
                s++;
                k/=j;
            }
            tmp[j]=max(tmp[j],s);
        }
        if(k>1)
            tmp[k]=max(tmp[k],1);
    }
    long long res=1;
    for(int i=1;i<=1e5;i++)
    {
        for(int j=0;j<tmp[i];j++){
            res=res*i%987654321;
        }
    }
    cout<<res<<endl;
    return 0;
}
