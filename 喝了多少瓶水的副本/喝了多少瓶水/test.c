#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int k = 20;//钱数；
	int p = 0;//喝完水剩的瓶子数；
	int p1 = 0;//落单的瓶子数；
	int num = 0;//喝水的总数；
	while (k != 0)
	{
		num = num + k;
		p = k + p1;
		k = p / 2;
		p1 = p % 2;
	}
	printf("可以喝 %d 瓶汽水\n", num);



	system("pause");
	return 0;
}
