#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20	//最大可以处理二十位以内的数字的运算 
typedef struct bigint{
	char *num;	//大整数数据域 
	int sign;	//大整数符号位 
	int digit;	//大整数位数 
}BIGINT;
 
BIGINT ScanfBigInt();	//大整数的读取处理函数 
void PrintBigInt(BIGINT BigInt);
void Add(BIGINT BigInt1,BIGINT BigInt2);
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2);
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2);
BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2);
BIGINT Sub(BIGINT BigInt1,BIGINT BigInt2);
 
int main(void)
{
	BIGINT BigInt1,BigInt2;
	BIGINT BigIntResult;
	int key;
	
	printf("请输入两个大整数：\n");
	BigInt1=ScanfBigInt();
	printf("您输入的第一个数是：");//测试代码 
 	PrintBigInt(BigInt1);	
 	
	BigInt2=ScanfBigInt();
 	printf("您输入的第二个数是：");//测试代码
 	PrintBigInt(BigInt2);
	
	printf("请输入序号选择相应的操作：\n");
	printf("1.求两个数的和。\n");
	printf("2.求两个数的差。");
	
	while(1){
		scanf("%d",&key);
		switch(key){
			case 1:	BigIntResult=AddTwoBigInt(BigInt1,BigInt2);	break;
			case 2:	BigIntResult=SubTwoBigInt(BigInt1,BigInt2); break;
			default:printf("请输入正确的序号！\n");				break;
		}
		if(key==1 || key==2){
			break;
		}
	}
 
	//结果输出部分 
	printf("计算结果为：");
	PrintBigInt(BigIntResult);
 
	free(BigInt2.num);
	free(BigInt1.num);
	return 0;
}
 
/*     a  b 
	1. +  - ：传入相减函数，返回结果即可。 
	2. -  + ：交换两个数，传入相减函数，返回结果即可。 
	3. +  + ：直接传入加法函数，返回结果即可。 
	4. -  - ：取反 执行相加函数，结果的符号保存为负号。 
*/
 
BIGINT AddTwoBigInt(BIGINT BigInt1,BIGINT BigInt2)
{
	BIGINT BigIntSum;
	char *swap;
	int flag;
	int digit,sign;
	flag=CompareBigInt(BigInt1,BigInt2);//比较两数绝对值的大小 
 
	if(flag==-1){//1 比 2 小 （绝对值）则交换两个数 
		swap=BigInt1.num;
		BigInt1.num=BigInt2.num;
		BigInt2.num=swap;
		 
		sign=BigInt1.sign;
		BigInt1.sign=BigInt2.sign;
		BigInt2.sign=sign;
		
		digit=BigInt1.digit;
		BigInt1.digit=BigInt2.digit;
		BigInt2.digit=digit;
	}//交换完成后BigInt1 >= BigInt2（绝对值）
	BigIntSum.num=(char *)malloc(sizeof(char)*(BigInt1.digit+2));
	BigIntSum.digit=BigInt1.digit;
	
	//两数同号 
	if(BigInt1.sign==1 && BigInt2.sign==1){// + +  两个正数相加   
		BigIntSum=Sum(BigInt1,BigInt2);
		BigIntSum.sign=1;
	}
	if(BigInt1.sign==-1 && BigInt2.sign==-1){// - -  两个负数相加  
		BigIntSum=Sum(BigInt1,BigInt2);
		BigIntSum.sign=-1;
	}
	
	//两数异号 
	if(BigInt1.sign+BigInt2.sign==0){
		if(flag==0){//b2==b1 结果为零  
			BigIntSum.sign=0;
			BigIntSum.digit=1;
			BigIntSum.num[0]='0';
		}
		else{//一定是b1>=b2
			BigIntSum=Sub(BigInt1,BigInt2);
		}
	}
	return BigIntSum;
}
 
/*   
	a-b = a+(-b)
*/
BIGINT SubTwoBigInt(BIGINT BigInt1,BIGINT BigInt2)
{
	BIGINT BigIntSub;
	BigInt2.sign=-BigInt2.sign;
	BigIntSub=AddTwoBigInt(BigInt1,BigInt2);
	return BigIntSub;
}
 
BIGINT Sum(BIGINT BigInt1,BIGINT BigInt2)//求和函数 
{
	BIGINT Int;
	int n,t;
	int i=0,j=0,cp=0;
	int k=0;
	t=BigInt1.digit > BigInt2.digit ? BigInt1.digit : BigInt2.digit;//取位数长的一个数为Int的数值域分空间 
	Int.num=(char *)malloc(sizeof(char)*(t+2));
	Int.digit=t; 
	t=0;
	//相加操作 BigInt1.num+BigInt2.num（注意BigInt1的绝对值大于BigInt2的绝对值） 
	while(i<BigInt1.digit || j<BigInt2.digit){
		if(i<BigInt1.digit && j<BigInt2.digit){//两个都没跑完 
			k=BigInt1.num[i++]-'0'+BigInt2.num[j++]-'0'+cp;
		}
		else{
			k=BigInt1.num[i++]-'0'+cp;
		}
		cp=k/10;
		Int.num[t++]=k%10+'0';//数字转字符 
	}
	if(cp!=0){
		Int.num[t++]='1';
		Int.digit=Int.digit+1;	
	}
	return Int;
}
 
BIGINT Sub(BIGINT BigInt1,BIGINT BigInt2)//传入的数据保证 BigInt1.num > BigInt2.num（绝对值）所以结果一定为正 
{
	BIGINT Int;
	int i,k;
	char temp;
	int digit1,digit2;
	int borrow=0;
	int key; 
	Int.num=(char *)malloc(sizeof(char)*(BigInt1.digit+2));	
	Int.sign=1;//返回数的结果一定为正 
	//公有的位数部分的相减操作 
	for(i=0;i<BigInt2.digit;i++){//循环的次数等于小的数的位数
		key=BigInt1.num[i]-BigInt2.num[i];
		if(key<0){//存在借位		
			Int.num[i]=10+key+'0'-borrow;
			borrow=1;
		}
		if(key>=0){//不存在借位 
			Int.num[i]=key+'0'-borrow;
			borrow=0;
		}
	}
	//下面处理BigInt1可能会多出的位数
	for(i=BigInt2.digit;i<BigInt1.digit;i++){
		Int.num[i]=BigInt1.num[i]-borrow;
		borrow=0;
	}
	//下面确定最后结果的位数 处理可能存在的前导0
	Int.digit=BigInt1.digit;
	for(k=Int.digit-1;k>=0 && Int.num[k]=='0';k--);
	if(k<Int.digit-1){//这个数有前导0 
		Int.digit=k+1;
	}
	return Int;
}
 
int CompareBigInt(BIGINT BigInt1,BIGINT BigInt2)//比较绝对值大小函数 
{
	int flag;
	int digit1,digit2;
	//digit1,digit2放到 最高位上
	digit1=BigInt1.digit-1;
	digit2=BigInt2.digit-1;
	if(digit1!=digit2){//位数不同 
		return digit1>digit2 ? 1 : -1 ;
	}
	while(digit1>=0){//位数相同 
		if(BigInt1.num[digit1]>BigInt2.num[digit1]){
			flag=1;
			break;
		}
		if(BigInt1.num[digit1]<BigInt2.num[digit1]){
			flag=-1;
			break;
		}
		digit1--;
	}
	if(digit1<0)//从while的条件退出循环 两数相等 
	flag=0;
	return flag; 
}
 
BIGINT ScanfBigInt()//大整数的输入处理 
{
	BIGINT BigInt;
	int bit,cnt;
	int i,j,k;
	char *tempnum=NULL;
	tempnum=(char *)malloc(sizeof(char)*(N+2));//多两个空间，一个预留存负号，一个存'\0' 
	BigInt.num=(char *)malloc(sizeof(char)*(N+2));
	printf("请输入大整数：");
	scanf("%s",tempnum);
	cnt=strlen(tempnum);
	BigInt.digit=cnt;	//确定大整数的位数
	if(tempnum[0]=='-'){//确定大整数的正负 
		BigInt.sign=-1;
		tempnum[0]='0';//把负号换成字符0，后面统一处理 
	}
	else{
		BigInt.sign=1;
	}
	for(i=0,j=cnt-1;i<cnt;j--,i++){//倒序保存大整数的值 
		BigInt.num[j]=tempnum[i];
	}
	//处理可能存在的前导0 
	for(k=BigInt.digit-1;k>=0 && BigInt.num[k]=='0';k--);
	if(k<BigInt.digit-1){//这个数有前导0 
		BigInt.digit=k+1;
	}
	if(k==-1){//这个数是0
		BigInt.digit=1;
	}
	free(tempnum);
	return BigInt;
}
 
void PrintBigInt(BIGINT BigInt)//打印大整数  
{
	int j;
	if(BigInt.sign==-1){
		printf("-");
	}
	for(j=BigInt.digit-1;j>=0;j--){
		printf("%c",BigInt.num[j]);
	}
	printf("\n");
}
 