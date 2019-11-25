#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int input = 0;
	int i = 0;
	int j = 0;
	int max = 0;
	scanf("%d",&input);
	for (i = 3; i < input;i++)
	{
		for (j = 2; j < i;j++)
		{
			if (i%j == 0)
			{
				break;
			}
			if (j == (i - 1) && i%j != 0)
			{
				if (i>max)
					max = i;
			}
		}
	}
	printf("%d\n",max);
	system("pause");
	return 0;
}