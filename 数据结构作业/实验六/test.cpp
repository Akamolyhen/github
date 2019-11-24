#include<iostream>
#include<string.h>
#define  UINT_iMAX 10000 
using namespace std;
 
typedef struct {
	char letter, *code;
	int weight;
	int parent, lchild, rchild;
}HTNode, *HuffmanTree;
 
 
int n;
char coding[100];
 
int Min(HuffmanTree &HT,int i)  
{  
    //在HT[1...i]中选择parent为0且权值最小的结点  
    //返回该结点的下标值  
    //此函数被Select函数调用  
    int j;  
    unsigned int k = UINT_iMAX;//假设各结点的权值不会超过UINT_MAX  
    int flag;  
    for(j = 0; j <= i; ++j)  
    {  
        if(HT[j].weight < k && HT[j].parent == 0)//用父结点是否为0来判断此结点是否已经被选过  
        {  
            k = HT[j].weight;  
            flag = j;  
        }  
    }  
    HT[flag].parent = 1;//作个标记，说明已经被选择了，因为在Select函数中要选择权值小的两个结点  
    return flag;  
}  
  
void Select(HuffmanTree &HT, int i, int &s1, int &s2)  
{  
    //在HT[1...i]中选择parent为0且权值最小的两个结点，其序号分别为s1,s2  
    //s1 <= s2  
    s1 = Min(HT,i);  
    s2 = Min(HT,i);  
}  
 
 
void CreateHuffmanTree(HuffmanTree &HT, char t[], int w[])
{
	//cout<<"nihao1"<<endl;
	int m;
	int i, s1, s2;
	if(n<=1)//如果只有一个就不用创建
	return ;
	m=2*n-1; //总共需要2n－1个节点
	HT=new HTNode[m+1];//开辟空间
	for(i=0; i<n; i++)
	{
		HT[i].code='\0';
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].letter=t[i];
		HT[i].weight=w[i]; 
	
	}
	for(i=n; i<=m; i++)
	{
		HT[i].code='\0';
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].letter=' ';
		HT[i].weight=0;
	}
	cout<<"++++++++++++++"<<endl;
	for(i=n; i<m; i++)
	{
	Select(HT, i-1,s1, s2);//在n个数中找出权值最小的两个
	
	HT[s1].parent=i;
	HT[s2].parent=i;//将他们两个的parent节点设置为i;
	
	HT[i].lchild=s1;
	HT[i].rchild=s2;//把这两个分别当作左右节点
	HT[i].weight=HT[s1].weight+HT[s2].weight;//他们两个的双亲为他们两个的和；
	
	}
}
 
void CreatHuffmanCode(HuffmanTree HT)
{
	int start, c, f;
	int i;
	char *cd=new char[n]; 
	
	cd[n-1]='\0';
	//for(i=0; i<2*n; i++)
//	cout<<HT[i].letter<<":"<<HT[i].lchild<<":"<<HT[i].rchild<<HT[i].weight<<endl;
	cout<<"字符编码为："<<endl;
	for(i=0; i<n; i++)
	{
	
	start=n-1;
	c=i;
	f=HT[i].parent;
	
		while(f!=0){
			--start;
			if(HT[f].lchild==c){
			
				cd[start]='0';
			}
			else{
			 
				cd[start]='1';
			}
			c=f;
			f=HT[f].parent;
		}
	
	HT[i].code=new char[n-start];
	strcpy(HT[i].code,&cd[start]);
	cout<<HT[i].letter<<":"<<HT[i].code<<endl;
	}
	
	delete cd;
	
}
 
 
 
void HuffmanTreeYima(HuffmanTree HT,char cod[],int b)           //译码
{ 
	char sen[100]; 
    char temp[50]; 
    char voidstr[]=" ";       //空白字符串
    int t=0; 
	int s=0; 
 	int xx=0;
    for(int i=0; i<b; i++)
	 { 
	 		temp[t++]=cod[i];     //读取字符
	        temp[t] = '\0';        //有效字符串
	        for(int j=0;j<n;j++){        //依次与所有字符编码开始匹配
		  	 
		  	 if (!strcmp(HT[j].code,temp)){                //匹配成功
		   
		    			sen[s]=HT[j].letter;    //将字符保存到sen中
		                s++; 
		  				xx+=t;
		                strcpy(temp,voidstr);                //将TEMP置空 
		                t=0;          //t置空
		                break;
		 	  }
		  } 
	 } 
	 if(t==0){     //t如果被置空了，表示都匹配出来了，打印译码
	 
	 sen[s]='\0';
	    cout<<"译码为:"<<endl; 
	 
	    cout<<sen<<endl;
	 }
	 else{                             //t如果没有被置空 ， 源码无法被完全匹配
	  cout<<"二进制源码有错！从第"<<xx+1<<"位开始"<<endl;
	 }
} 
 
 
 
int main()  
{  
    HuffmanTree HT;  
    //HuffmanCode HC;  
    char a[100], buff[1024], p;//a为存放字符 buff为输入的字符串 p为输入译码时的字符 
    int b[100];//存放权值信息 
    int  i, j;
	int symbol=1, x, k; //译码时做判断用的变量  
    cout<<"请输入一段文字:";
    cin.getline(buff,1024);
    
    
    int len=strlen(buff);
 	for (i=0;i<len;i++)
 	{
 		//	cout<<n<<"________________"<<endl; 
		  for(j=0; j<n;  j++)
		  {
				   if (a[j]==buff[i])
				   {
				   	 	b[j]=b[j]+1;
				    	break;
				   }
		  }
		if (j>=n)
		{
			a[n]=buff[i];
			b[n]=1;
			n++;
		}
 	}
 
//	cout<<n<<"________________"<<endl; 
	cout<<"字符和权值信息如下"<<endl;
	 for (i=0;i<n;i++)
	 {
	  cout<<"字符："<<a[i]<<"  权值："<<b[i]<<endl;
	 }
 
    
    CreateHuffmanTree(HT, a, b);
    CreatHuffmanCode(HT);
    
//////////////////////////////////////////////////////////////////////
    
     cout<<"译码："<<endl;
 
 	while(1)
 	{ 
  		cout<<"请输入要译码的二进制字符串,输入'#'结束：";
   		x=1;//判断是否有非法字符只能是0 1 
   		k=0;//作为循环变量来使coding【k】=输入的字符 
   		symbol=1;//判断是否输入结束 
 		 while(symbol){ 
   			cin>>p; 
   			if(p!='1'&&p!='0'&&p!='#'){ //若存在其它字符，x设为0，表示输入的不是二进制
   			 	x=0;
   			}
  			coding[k]=p;
   			if(p=='#')  
    		symbol=0;  //#号结束标志
  
  			 k++;
  		}
 		 if(x==1){
 
  		HuffmanTreeYima(HT,coding,k-1);        //进行译码
 
  		}
  		else{
  			 cout<<"有非法字符！"<<endl;
  
  		}
	  cout<<"是否继续?(Y/N):";
	  cin>>p;
	  if(p=='y'||p=='Y')
	   continue;
	  else
	   break;
 	}
    
    
    return 0;  
}  