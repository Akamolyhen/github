#include<stdio.h>
int main()
{
	int num,sum;
	num=sum=7;
	sum=num++;//7
	sum++;//8
	++num;
	printf("%d",sum);
	return 0;
}
