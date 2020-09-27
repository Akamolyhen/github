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
/*#include<iostream>
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
    






}*/

/*#include<iostream>
using namespace std;
string s;
int main()
{
    cin>>s;
    char c=s[0];
    double n=1,d,res;
    for(int i=1;i<s.length();i++){
        if(c!=s[i]){
            c=s[i];
            n++;
        }
       
       
        
    }
     d=(double)s.size()/n;
     res=(int)((d+5e-3)*100)/100.00;
    cout<<res<<endl;
}
*/
/*#include <bits/stdc++.h>

using namespace std;
const int maxn=50+5;
int n, L;
int parent[maxn];
int dp[200];
int main()
{
      while (cin >> n >> L) {
       for (int i = 1; i <= n - 1; i++) {
           cin >> parent[i];
       }
       dp[0] = 0; int hight = 0;
       for (int i = 1; i <= n - 1; i++) {
           dp[i] = dp[parent[i]] + 1;
           hight = max(hight, dp[i]);//求出树的深度
       }
       if (L <= hight) { cout << L + 1 << endl;  return 0;}
       else {
           cout << min(n, hight + 1 + (L - hight) / 2)<<endl;
           return 0;
          
       }//注意最多也就是把所有的城市都游完
 }*/
   





/*#include<iostream>
using namespace std;
int n;
int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int cnt4=0,cnt2=0,cnt1=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x%4==0)
            cnt4++;
            else if(x%2==0)
            cnt2++;
            else cnt1++;
        }
        if(cnt2==0){
            if(cnt4>=cnt1-1)
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }
        else{
            if(cnt4>=cnt1)
            cout<<"Yes"<<endl;
            else
            cout<<"No"<<endl;
        }
    }
    return 0;
}

*/
/*
#include<bits/stdc++.h>
using namespace std;
const int maxn=50+5;
int x[maxn],y[maxn];
int n;
int solve(){
    if(n<=2)
        return n;
    int res=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                int dx1=x[j]-x[i];
                int dy1=y[j]-y[i];
                for(int k=0;k<n;k++){
                    if(i!=k&&j!=k){
                        int cnt=0;
                        if(i!=k&&j!=k)
                        {
                            for(int r=0;r<n;r++){
                                int dx2=x[r]-x[i];
                                int dy2=y[r]-y[i];
                                if(dy1*dx2==dy2*dx1){
                                    cnt++;
                                }
                                else{
                                    dx2=x[r]-x[k];
                                    dy2=y[r]-y[k];
                                    if(dy1*dy2==-dx2*dy1){
                                        cnt++;
                                    }
                                }
                            }
                        }
                        res=max(res,cnt);
                    }
                }
            }
        }
    }
    return res;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>y[i];
    cout<<solve()<<endl;
    
}

*/
/*
#include<bits/stdc++.h>
using namespace std;
void TestFree()
{
    
    char* str=new char[10];
    strcpy(str,"hello");
    delete[](str);
    if(str!=NULL)
    {
        cout<<str<<endl;
        str=NULL;
    }
    
}
void test(char str[20]);
int main()
{
    char s[]="dgs";
    char str[20];
    cout<<sizeof(s)/sizeof(char)<<endl;
    cout<<strlen(s)<<endl;
    int *a;
    int * &p=a;
    int b=8;
    p=&b;
    
     
    test(str);
    //TestFree();
    return 0;
}
void test(char str[20])
{
    strcpy(str,"Hello!");
     cout<<strlen(str)<<endl;
  
}
*/
/*#include<bits/stdc++.h>
using namespace std;
/// 只用逻辑运算实现乘法运算
int mul(int a,int b)
{
    bool neg=(b<0);
    if(b<0)
        b=-b;
    int sum=0;
    map<int,int> bit_map;
    for(int i=0;i<32;i++)
    {
        bit_map.insert(pair<int,int>(1<<i,i));
    }
    while(b>0)
    {
        int last_bit=bit_map[b&~(b-1)];
        sum+=(a<<last_bit);
        b&=b-1;
    }
    if(neg)
        sum=-sum;
    return  sum;
}
int main()

{
    cout<<mul(3, 5)<<endl;
    return 0;
}

*/


/*#include<bits/stdc++.h>
using namespace std;
int add2(int num,...){
    va_list arg_ptr;
    int i;
    int sum=0;
    va_start(arg_ptr, num);
    for(i=0;i<num;i++)
    {
        sum+=va_arg(arg_ptr, int);
    }
    va_end(arg_ptr);
    return sum;
}
int main()
{
    int i=1,j=2,k=3;
    cout<<add2(3,i,j,k)<<endl;
    return 0;
}
*/

/*#include<bits/stdc++.h>
using namespace std;

char _map[1000][1000];
int main()

{
    int i,j,m,n,tot;
    char ch='A';
    cin>>m>>n;
    /*for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    _map[i][j]='0';*/
 /*   memset(_map, '0', sizeof(_map));
    i=j=tot=0;
    _map[i][j]='A';
    while(tot<n*m-1)
    {
        while(j+1<n&&_map[i][j+1]=='0')
        {
            if(ch>=90)
                ch-=26;
            j++;
            ch++;
            _map[i][j]=ch;
            tot++;
        }
        while(i+1<m&&_map[i+1][j]=='0')
        {
            if(ch>=90)
                ch-=26;
            i++;
            ch++;
            _map[i][j]=ch;
            tot++;
        }
        while(j-1>=0&&_map[i][j-1]=='0')
        {
            if(ch>=90)
                 ch-=26;
            j--;
            ch++;
            _map[i][j]=ch;
            tot++;
        }
        while(i-1>=0&&_map[i-1][j]=='0')
        {
            if(ch>=90)
                ch-=26;
            i--;
            ch++;
            _map[i][j]=ch;
            tot++;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<_map[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
            
}
*/

/*
#include<bits/stdc++.h>
#define radix 10
using namespace std;

int myatoi(const char* str)
{
    assert(str!=NULL);
    while(*str==' ')
    {
        str++;
    }
    int nSign=(*str=='-')? -1:1;//确定符号位
    if(*str=='+'||*str=='-')
    {
        str++;
    }
    int nResult=0;
    while(*str>'0'&&*str<'9')
    {
        nResult=nResult*radix+(*str-'0');
        str++;
    }
    while(*str==' ')
    {
        str++;
        if(*str=='\0')
            break;
    }
    if(*str!='\0')
    {
        cout<<"Invalid Input"<<endl;
        return -1;
    }
    return nResult*nSign;
}
char* myitoa(int num,char* str)
{
    char* ptr=str;
    int temp;
    int sign=num,i=0,j=0;
    if(sign<0)
    {
        num=-num;
    }
    while(num)
    {
        *ptr++ = num%radix+'0';
        num/=radix;
        if(num<radix)
        {
            *ptr++=num+'0';
            break;
        }
    }
    if(sign<0)
    {
        *ptr++='-';
    }
    *ptr='\0';
    j=(int)(ptr-str-1);
    for(i=0;i<j;i++,j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
       
    }
    return str;
}
int main()
{
    const char *str="  -6545  ";
    char str1[10];
    cout<<myatoi(str)<<endl;
    cout<<myitoa(-34233, str1)<<endl;
    return 0;
}
*/
/*#include<bits/stdc++.h>

using namespace std;
int main()
{
    
}
*/
/*#include<iostream>
#include<map>
using namespace std;
bool findMost(int *a,int size,int &val){
    if(size==0)
        return false;
    map<int,int> m;
    for(int i=0;i<size;i++)
    {
        if(++m[a[i]]>=m[val])
            val=a[i];
    }
    return true;
}
int main()
{
    int a[]={1,2,3,4,4,4,5,5,5,5,6};
    int val=0;
    if(findMost(a, 11, val))
        cout<<val<<endl;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
void findElemnt(int a[],int length)
{5
    int s=0;
    int i;
    int k=0;
    for(i=0;i<length;i++)
    {
        s^=a[i];
    }
    int s1=s;
    int s2=s;
    while(!(s1&1))
    {
        s1=s1>>1;
        k++;
    }
    for(i=0;i<length;i++)
    {
        if((a[i]>>k)&1)
            s^=a[i];
        
    }
    cout<<s<<" "<<(s^s2)<<endl;
}

int main()
{
    int array[]={1,2,2,3,3,4,1,5};
    int len=sizeof(array)/sizeof(array[0]);
    findElemnt(array, len);
    return 0;
}
