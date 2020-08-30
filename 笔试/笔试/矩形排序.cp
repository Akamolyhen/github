#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Than(vector<int>v,int n);

int main()
{
    int N;
    cin>>N;
    int Ns=N;
    vector<int>v;
    int w,h;
    while(N--)
    {
        cin>>w;
        cin>>h;
        v.push_back(w);
        v.push_back(h);
    }
    Than(v,Ns);//处理和比较
}

void Than(vector<int>v,int n)
{
    int max=0;
    for(int i=0;i<2*n;i+=2)
    {
        if(v[i]*v[i+1]>max)
        {
            max=v[i]*v[i+1];
        }
        else if(v[i]*v[i+1]==max)
        {
            int temp=min(v[i]/v[i+1],v[i+1]/v[i]);
            int temp1=min(v[i-2]/v[i-1],v[i-1]/v[i-2]);
            if(temp>temp1)
            {
                int w=v[i-2];
                int h=v[i-1];
                v[i-2]=v[i];
                v[i]=w;
                v[i-1]=v[i+1];
                v[i+1]=h;
                i=-2;
                max=0;
            }
            else if(temp==temp1)
            {
                if(v[i]<v[i-2])
                {
                    int w=v[i-2];
                    int h=v[i-1];
                    v[i-2]=v[i];
                    v[i]=w;
                    v[i-1]=v[i+1];
                    v[i+1]=h;
                    i=-2;
                    max=0;
                }
                else
                    continue;
            }
        
        }
        else
        {
            int w=v[i];
            int h=v[i+1];
            v[i]=v[i-2];
            v[i-2]=w;
            v[i+1]=v[i-1];
            v[i-1]=h;
            i=-2;
            max=0;
        }
    }
    /*cout << "输出结果如下：" << endl;
    cout << "宽高序列：" << endl;*/
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)  //输出矩形宽高序列
    {
        cout << *it<<" ";
    }
   /* cout << endl;
    cout << "面积序列：" << endl;
    for (vector<int>::iterator it = v.begin(); it < v.end(); it+=2)  //输出矩形面积序列
    {
        cout << *it*(*(it+1)) << " ";
    }
    cout << endl;*/
}
