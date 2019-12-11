#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				for (d = 0; d <= 1; d++)
				{
					if (((a == 0) + (c == 1) + (d == 1) + (d == 0)) == 3)//四个人中只有三个人说的是真话；
					{
						if (a == 1)
						{
							printf("a是凶手\n");
							goto there;
						}
						if (b == 1)
						{
							printf("b是凶手\n");
							goto there;
						}
						if (c == 1)
						{
							printf("c是凶手\n");
							goto there;
						}
						if (d == 1)
						{
							printf("d是凶手\n");
							goto there;
						}
					}
				}
			}
		}
	}
there:
	system("pause");
	return 0;
}