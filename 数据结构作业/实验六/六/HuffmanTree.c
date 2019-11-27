//HuffmanTree.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "HuffmanTree.h"
 
 
 
int min1(HuffmanTree t,int i)
 { /* 返回i个结点中权值最小的树的根结点序号，函数select()调用 */
	int j,flag;
	unsigned int k=10000000; /* 取k为不小于可能的值(无符号整型最大值) */
	for(j=1;j<=i;j++)
		if(t[j].weight<k&&t[j].parent==0) /* t[j]是树的根结点 */
			k=t[j].weight,flag=j;
		t[flag].parent=1; /* 给选中的根结点的双亲赋1，避免第2次查找该结点 */
		return flag;
 }
 
 
void select(HuffmanTree t,int i,int *s1,int *s2)
{ /* 在i个结点中选择2个权值最小的树的根结点序号，s1为其中序号小的那个 */
	int j;
	*s1=min1(t,i);
	*s2=min1(t,i);
	if(*s1>*s2)
	{
		j=*s1;
		*s1=*s2;
		*s2=j;
	}
 }
 
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n) /* 算法6.12 */
{ /* w存放n个字符的权值(均>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC */
	int m,i,s1,s2,start,num=0;
	unsigned c,f;
	HuffmanTree p;
	char *cd;
	if(n<=1)
		return;
	m=2*n-1;    //开辟的空间 比元素个数多 因为后续生成的新子树要用到
	*HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode)); /* 0号单元未用 */
	for(p=*HT+1,i=1;i<=n;++i,++p,++w,++num)
	{
		(*p).weight=*w; //这部分是给确定的子树赋值，包括字母a-z 权值从数组中得出
			if(i<26)
				(*p).ch=97+num;
			else if(i==26)
			{
				(*p).ch=97+num;
				num=-1;
			}
			else if(i<=52&&i>26)
				(*p).ch=65+num;
			else if(i==53)
				(*p).ch=32;
			else if(i==54)
				(*p).ch='\n';
		(*p).parent=0;
		(*p).lchild=0;
		(*p).rchild=0;
	}
	for(;i<=m;++i,++p)
		(*p).parent=0;
	for(i=n+1;i<=m;++i) /* 建赫夫曼树 */
	{ /* 在HT[1～i-1]中选择parent为0且weight最小的两个结点，其序号分别为s1和s2 */
		select(*HT,i-1,&s1,&s2);
		(*HT)[s1].parent=(*HT)[s2].parent=i;     //这部分给后面要用到的新节点 初值
		(*HT)[i].lchild=s1;
		(*HT)[i].rchild=s2;
		(*HT)[i].ch='!';                        //他们存放的是!   所以可以判断此节点是否有意义
		(*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
	}
 
 
//哈夫曼 编码 的求出  保存在HC里面（二维数组）
 
 
 
	/* 从叶子到根逆向求每个字符的赫夫曼编码 */
	*HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
	/* 分配n个字符编码的头指针向量([0]不用) */
	cd=(char*)malloc(n*sizeof(char)); /* 分配求编码的工作空间 */
	cd[n-1]='\0'; /* 编码结束符 */
	for(i=1;i<=n;i++)
	{ /* 逐个字符求赫夫曼编码 */
		start=n-1; /* 编码结束符位置 */
		for(c=i,f=(*HT)[i].parent;f!=0;c=f,f=(*HT)[f].parent)
			/* 从叶子到根逆向求编码 */
			if((*HT)[f].lchild==c)
				cd[--start]='0';
			else
				cd[--start]='1';
			(*HC)[i]=(char*)malloc((n-start)*sizeof(char));
			/* 为第i个字符编码分配空间 */
			strcpy((*HC)[i],&cd[start]); /* 从cd复制编码(串)到HC */
	}
	free(cd); /* 释放工作空间 */
}
 
 
void getWeightInfile(int *w)    
{
	FILE *pfr;
	int i=0;
	pfr = fopen("记录信息\\mytxt.txt", "r");//读取文件
	if (pfr==NULL)
	{
		printf("文件操作失败");
		return ;
	}
	else
	{
		while (!feof(pfr))     //直到文件读取完毕，每次读取一行
		{
			char str[256] = {0};
			fgets(str, 256, pfr);//读取一行
			i=0;
			while(str[i]!=0)    //如果这是个字母，那么对应数组的从0-25 发现一个 对应的值加加  实现计算文件中字母的个数
			{	
				if(str[i]<='z' && str[i]>='a')      //97-122   65-90  32
					w[str[i]-97]++;
				if(str[i]<='Z'&& str[i]>='A')
					w[str[i]-65+26]++;
				if(str[i]==' ')
					w[26*2]++;
				if(str[i]=='\n')
					w[26*2+1]++;
				i++;
				
			}			
		}
	}
	fclose(pfr);
}                    //文件用完要关闭
 
 
 
void bianMaInFile(HuffmanTree *p,HuffmanCode cd)
{
	FILE *pfr;
	FILE *pfw;
	//HuffmanTree ptr=(*p)+1;
	int i;
	int num;
	int count=1;
	pfr = fopen("记录信息\\mytxt.txt", "r");//读取文件
	pfw = fopen("记录信息\\编码.txt","w");//写入文件
	if (pfr==NULL || pfw==NULL)
	{
		printf("文件操作失败");
		return ;
	}
	else 
	{
		while (!feof(pfr))
		{
			char str[256] = {0};
			fgets(str, 256, pfr);//读取一行
			i=0;
			num=-1;
			while(str[i]!=0)
			{	
				
				if(str[i]<=122 && str[i]>=97)     //1-26
							num=str[i]-96;
				else if(str[i]<=90 && str[i]>=65)  //27-52
							num=str[i]-64+26;
				else if(str[i]==32)   
							num=53;
				else if(str[i]=='\n')
							num=54;
				if(num!=-1)//就把cd里面的编码 输出到 编码.txt里面
				{
					if(count==1)
						count++;
					else
						//fputs(cd[num], pfw); 
						fprintf(pfw,"%s\n",cd[num]);
				}
				i++;
				num=-1;
				
			}			
		}
		fclose(pfr);
		fclose(pfw);
	}
}
 
void yimaInFile(HuffmanTree *p)
{
	FILE *pfr;
	FILE *pfw;
	char s[2]={0};
	int i=0,num=107;  //51=2*26-1    2*54-1
	int n;
	pfr = fopen("记录信息\\编码.txt", "r");//读取文件
	pfw = fopen("记录信息\\译码.txt","w");//写入文件
	if (pfr==NULL || pfw==NULL)
	{
		printf("文件操作失败");
		return ;
	}
	else 
	{
		while (!feof(pfr))
		{
			char str[255] = {0};			
			fgets(str, 255, pfr);
			i=0;//读取一行
			num=107;
			while(str[i]!=0)
			{	n=i;
				while(str[i]!=0)
				{
					if((*p)[num].ch!='!')            //如果发现 左右移动找到了字母 立马退出 匹配下一个
						break;
					if(str[i]=='0')                 //0左1右
						num=(*p)[num].lchild;
					else if(str[i]=='1')
						num=(*p)[num].rchild;					
					i++;
				}
				if((*p)[num].ch=='!' && str[i]!='\0')
					printf("因为编码不全,%d-%d个编码被舍掉\n",n+1,i);
				else if(str[i]!='\0')
				{	
					s[0]=(*p)[num].ch;
					fputs(s, pfw);
				}
				num=107;
				
			}
		}
	}
	fclose(pfr);
	fclose(pfw);
}
 