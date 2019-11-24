#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int input = 0;
	int i = 0;
	printf("请输入一个整数：");
	scanf("%d", &input);
	for (i = 0; i < 32; i++)
	{
		printf("%d ", (input >> (32 - 1 - i)) & 1);
	}
	printf("\n");
	system("pause");
	return 0;
}