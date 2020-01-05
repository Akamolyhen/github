#ifndef __GAME_H_
#define __GAME_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ROW 9//棋盘的行数；
#define COL 9//棋盘的列数；
#define NUMBER 79//布置雷的个数；



void meau();//菜单函数；
void game();//游戏主题；
void test();//测试函数；
void init_conceal();//初始化真实数组函数；
void init_show();//初始化显示数组函数；
void output_conceal();//打印真实数组；
void output_show();//打印显示数组；
void set();//随机布雷；
void find();//找雷函数；
void spread();//展开函数，用于周围没有雷时将其展开，无需将所有不是雷的坐标都输入；
int judge();//判断剩余的'*'是否等于雷的个数；
#endif   //__GAME_H_