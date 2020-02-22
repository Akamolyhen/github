#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)//第一种方法；
{
	int num = 0;
	while (value != 0)
	{
		if ((value % 2) == 1)
		{
			num++;
			value = value / 2;
		}
	}
	return num;
}

//int count_one_bits(unsigned int value)//第二种方法；
//{
//	int num = 0;
//	while (value != 0)
//	{
//		if ((value & 1) == 1)
//		{
//			num++;
//			value >>= 1;
//		}
//	}
//	return num;
//}


int main()
{
	int i = 0;
	printf("请输入一个数字：");
	scanf("%d", &i);
	printf("有%d个'1'\n", count_one_bits(i));
	system("pause");
	return 0;
}