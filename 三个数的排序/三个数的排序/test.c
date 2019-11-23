#define _CRT_SECURE_NO_WARNING 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max = 0;
	printf("请输入三个数：\n");
	scanf_s("%d,%d,%d", &a, &b, &c);
	if (a > b > c)
		printf("%d,%d,%d", a, b, c);
	else if (a > c > b)
		printf("%d,%d,%d", a, c, b);
	else if (b> a > c)
		printf("%d,%d,%d", b, a, c);
	else if (b> c > a)
		printf("%d,%d,%d", b, c, a);
	else if (c> a> b)
		printf("%d,%d,%d", c, a, b);
	else
		printf("%d,%d,%d", c, b, a);
	system("pause");
	return 0;
}