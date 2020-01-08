#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char input[10];
	int i = 0;
	char mima[] = { "2580" };
	printf("您共有三次机会\n");

	for (i = 0; i < 3; i++)
	{	
		printf("请输入密码:");
	    scanf("%s",&input);
		if (strcmp(mima, input) == 0)
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			if ((2 - i) == 0)
			{
				printf("三次机会用完，退出程序\n");
				break;
			}
			printf("密码错误，您还有%d次机会，请重新输入\n",2-i);
			continue;
		}
	}
	system("pause");
	return 0;
}