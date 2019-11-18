#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int t = 0;
	int f = 0;
	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 14 - 2 * i; j++)
		{
			printf(" ");

		}
		for (k = 1; k <= -3 + 4 * i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 8; i <= 13; i++)
	{
		for (t = 1; t <= -14 + 2 * i; t++)
		{
			printf(" ");
		}
		for (f = 1; f <= 53 - 4 * i; f++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}