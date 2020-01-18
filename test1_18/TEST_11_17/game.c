#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void meau()//游戏菜单
{
	printf("****************************************\n");
	printf("**** 1.play            0.exit **********\n");
	printf("****************************************\n");
}


void init_conceal(char main[ROW+2][COL+2], char M, int row, int col)//初始化真实数组函数；
{
	memset(main, M, row*col*sizeof(main[0][0]));
}

void init_show(char main[ROW][COL], char M, int row, int col)//初始化显示数组函数；
{
	memset(main, M, row*col*sizeof(main[0][0]));
}



void output_conceal(char main[ROW+2][COL+2], int cow, int col)//打印真实数组函数；
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cow; i++)
	{	
		if (i < 10)//防止当行数为二位数时出现真实数组中元素打印出来错行，影响美观；
		{
			printf(" %d ", i);//打印行标；
		}
		else
		{
			printf(" %d", i);//打印行标；
		}
			for (j = 0; j < col; j++)
			{
				printf(" %c ", main[i][j]);
			}
			printf("\n");
		}
	printf("   ");
	for (i = 0; i < col; i++)
	{
		printf(" %d ", i);//打印列标；
	}
	printf("\n");
}


void output_show(char main[ROW][COL], int cow, int col)//打印显示数组函数；
{
	int i = 0;
	int j = 0;
	for (i = 0; i < cow; i++)
	{
		printf(" %d ", i );//打印行标；
		for (j = 0; j < col; j++)
		{
			printf(" %c ", main[i][j]);
		}
		printf("\n");
	}
	printf("   ");
	for (i = 0; i < col; i++)
	{
		printf(" %d ", i);//打印列标；
	}
	printf("\n");
}


void set(char main[ROW+2][COL+2], int row, int col)//随机布雷；
{
	int x = 0;
	int y = 0;
	int count = NUMBER;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % row + 1;
		if (main[x][y] == '0')//防止一个地方被二次布雷；
		{
			main[x][y] = '1';
			count--;
		}
		else
		{
			;
		}
	} 
}


//void spread(char main1[ROW + 2][COL + 2], char main2[ROW][COL], int input_x, int input_y)//展开函数，在周围没有雷的情况下将其展开;不过最后没写出来，也没找到原因；
//{
//	/*int H = 0;
//	int i = 0;
//	int j = 0;
//	if (input_x > 1 && input_x<10 && input_y>1 && input_y < 10)
//	{*/
//	//	H = main1[input_y - 1][input_x - 1] + main1[input_y - 1][input_x] + main1[input_y - 1][input_x + 1] + main1[input_y][input_x - 1] +
//	//		main1[input_y][input_x + 1] + main1[input_y + 1][input_x - 1] + main1[input_y + 1][input_x] + main1[input_y + 1][input_x + 1] - 8 * '0';//计算用户所选点的周围的雷的个数；
//	//	if (H == 0)
//	//	{
//	//		main2[input_y - 1][input_x - 1] = 32;
//	//		for (i = input_x - 1 - 1; i <= input_x; i++)
//	//		{
//	//			for (j = input_y - 1 - 1; j <= input_y; j++)
//	//			{
//	//				if (i == input_x - 1 && j == input_y - 1)
//	//				{
//	//					continue;
//	//				}
//	//				else if (main2[j][i] == '*')
//	//				{
//	//					spread(main1, main2, i, j);
//	//				}
//	//			}
//	//		}
//	//	}
//	//	else
//	//	{
//	//		main2[input_y-1][input_x-1] = H + 48;
//	//	}
//	//}
//	int B = 0;
//    B = main1[input_y - 1][input_x - 1] + main1[input_y - 1][input_x] + main1[input_y - 1][input_x + 1] + main1[input_y][input_x - 1] +
//			main1[input_y][input_x + 1] + main1[input_y + 1][input_x - 1] + main1[input_y + 1][input_x] + main1[input_y + 1][input_x + 1] - 8 * '0';
//	if (B == 0)
//	{
//		main2[input_y - 1][input_x - 1] = ' ';
//		if ((input_y - 1) > 0 && (input_x - 1) > 0 && (main2[input_y - 1][input_x - 1]))
//			spread(main1, main2, input_y - 1, input_x - 1);
//		if ((input_y - 1) > 0 && (input_x ) > 0 && (main2[input_y - 1][input_x]))
//			spread(main1, main2, input_y - 1, input_x);
//		if ((input_y - 1) > 0 && (input_x+1) > 0 && (main2[input_y - 1][input_x+1]))
//			spread(main1, main2, input_y - 1, input_x+1);
//		if ((input_y ) > 0 && (input_x - 1) > 0 && (main2[input_y ][input_x - 1]))
//			spread(main1, main2, input_y , input_x - 1);
//		if ((input_y ) > 0 && (input_x + 1) > 0 && (main2[input_y ][input_x + 1]))
//			spread(main1, main2, input_y , input_x + 1);
//		if ((input_y+1) > 0 && (input_x - 1) > 0 && (main2[input_y+1][input_x - 1]))
//			spread(main1, main2, input_y+1, input_x - 1);
//		if ((input_y + 1) > 0 && (input_x) > 0 && (main2[input_y + 1][input_x ]))
//			spread(main1, main2, input_y + 1, input_x );
//		if ((input_y + 1) > 0 && (input_x+1) > 0 && (main2[input_y + 1][input_x+1]))
//			spread(main1, main2, input_y + 1, input_x+1);
//	}
//	else
//	{
//		main2[input_y - 1][input_x - 1] = B + 48;
//	}
//
//}


int judge(char main2[ROW][COL])//统计剩余的“*”的个数；
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (main2[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}








void find(char main1[ROW + 2][COL + 2], char main2[ROW][COL])
{
	int input_x = 0 ;
	int input_y = 0;
	int user_x =0;
	int user_y = 0;
	int T = 1;
	int B = 0;//计算周围雷的个数；
	int count = 1;
	int s = 0;
	while (T)
	{
		printf("请玩家输入坐标(坐标格式为：  横，纵   输入完成后按下回车):");
		scanf("%d,%d", &user_x, &user_y);
		printf("\n");
		if ( user_x <0)//判断用户输入的坐标是否符合规定；
		{
			printf("坐标输入有误，请重新输入；\n");
			T = 1;
			continue;
		}
		if ( user_x > (COL - 1))
		{
			printf("坐标输入有误，请重新输入；\n");
			T = 1;
			continue;
		}
		if ( user_y < 0)
		{
			printf("坐标输入有误，请重新输入；\n");
			T = 1;
			continue;
		}
		if ( user_y > (ROW - 1))
		{
			printf("坐标输入有误，请重新输入；\n");
			T = 1;
			continue;
		}
		T = 0;
	}
	T = 1;//为了下一次使用T做好准备；
	input_y = user_y + 1;
	input_x = user_x + 1;
	if (main1[input_y][input_x] == '1')
	{
		main1[input_y][input_x] = '0';//在用户第一次选到雷的时候，将这个雷删掉，防着第一次就被炸死，没有游戏体验；
		while (count)
		{
			input_x = rand() % ROW + 1;
			input_y = rand() % ROW + 1;
			if (main1[input_x][input_y] == '0')//防止一个地方被二次布雷；
			{
				main1[input_x][input_y] = '1';//将刚才删掉的雷补上；
				output_conceal(main1, ROW + 2, COL + 2);//打印真实数组，实际运行时不显示真实数组；
				count = 0;
			}
			else
			{
				count=1;
			}
		}
	}
	input_y = user_y + 1;
	input_x = user_x + 1;
	B = main1[input_y - 1][input_x - 1] + main1[input_y - 1][input_x] + main1[input_y - 1][input_x + 1] + main1[input_y][input_x - 1] +
		main1[input_y][input_x + 1] + main1[input_y + 1][input_x - 1] + main1[input_y + 1][input_x] + main1[input_y + 1][input_x + 1] - 8 * '0';//计算用户所选点的周围的雷的个数；
	main2[user_y][user_x] = B+48;
	//spread(main1, main2, input_x, input_y);//展开函数，在周围没有雷的情况下将其展开；
	output_show(main2, ROW, COL);//打印显示数组；
	printf("\n");
	while (1)
	{
		while (T)
		{
			printf("请玩家输入坐标(坐标格式为：  横，纵   输入完成后按下回车):");
			scanf("%d,%d", &user_x, &user_y);
			printf("\n");
			if (user_x <0)//判断用户输入的坐标是否符合规定；
			{
				printf("坐标输入有误，请重新输入；\n");
				T = 1;
				continue;
			}
			if (user_x >(COL - 1))
			{
				printf("坐标输入有误，请重新输入；\n");
				T = 1;
				continue;
			}
			if (user_y < 0)
			{
				printf("坐标输入有误，请重新输入；\n");
				T = 1;
				continue;
			}
			if (user_y >(ROW - 1))
			{
				printf("坐标输入有误，请重新输入；\n");
				T = 1;
				continue;
			}
			T = 0;
		}
		T = 1;
		input_y = user_y + 1;
		input_x = user_x + 1;
		if (main1[input_y][input_x] == '1')
		{
			printf("很抱歉，你被炸死了\n");
			main2[user_y][user_x] = 33;
			output_show(main2, ROW, COL);//打印显示数组；
			printf("\n");
			break;
		}
		else
		{
			B = main1[input_y - 1][input_x - 1] + main1[input_y - 1][input_x] + main1[input_y - 1][input_x + 1] + main1[input_y][input_x - 1] +
				main1[input_y][input_x + 1] + main1[input_y + 1][input_x - 1] + main1[input_y + 1][input_x] + main1[input_y + 1][input_x + 1] - 8 * '0';//计算用户所选点的周围的雷的个数；
			main2[user_y][user_x] = B + 48;
			output_show(main2, ROW, COL);//打印显示数组；
			printf("\n");	
			s = judge(main2);
		if (s ==NUMBER)
		{
			printf("恭喜你，扫雷成功!!!\n");
			break;
		}
		}
		//spread(main1, main2, input_x, input_y);//展开函数，在周围没有雷的情况下将其展开；

		output_show(main2, ROW, COL);//打印显示数组


	}

}