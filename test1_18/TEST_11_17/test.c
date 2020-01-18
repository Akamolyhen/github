#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	char conceal_main[ROW + 2][COL + 2];//真实的数组；
	char show_main[ROW][COL];//展示的数组；
	init_conceal(conceal_main, '0', ROW + 2, COL + 2);//初始化真实数组；
	init_show(show_main, '*', ROW, COL);//初始化展示数组；
	//output_conceal(conceal_main, ROW + 2, COL + 2);//打印真实数组，实际运行时不显示真实数组；
	printf("________________________________________\n");
	printf("________________________________________\n");
	output_show(show_main, ROW, COL);//打印显示数组；
	set(conceal_main, ROW, COL);//随机布雷；
	printf("________________________________________\n");
	printf("________________________________________\n");
	//output_conceal(conceal_main, ROW + 2, COL + 2);//打印布雷后的真实数组，方便编译者查看是否布雷成功，实际运行时不显示；
	find(conceal_main,show_main);//找雷函数；
}


void test()//测试函数，测试代码；
{
	int input = 0;
	do
	{
		srand((unsigned int)time(NULL));
		meau();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
	} while (input);
}


int main()
{
	test();

	system("pause");
	return 0;
}