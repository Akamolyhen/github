#include <stdio.h>
#include <unistd.h>	
#include <stdlib.h>	
#include <termios.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
//color choose
#define BLUE	"\033[0;32;24m"
#define RED		"\033[0;31;24m"
#define DEPBLUE	"\033[0;34;24m"
#define NONE	"\033[0m"

#define CLEAR() printf("\033[2J")
//反显
#define HIGHT_LIGHT() printf("\033[7m")
#define UN_HIGHT_LIGHT() printf("\033[27m")
#define RESET printf(NONE)

#define MOVETO(x,y) printf("\033[%d;%dH",(y),(x))

#define AREA_HIGHT 20
#define AREA_WIDHT 40
#define MAX_LENGTH 50

int snake_length = 3;
int score = 0;
int ver = 1;
int speed = 7;

typedef enum {UP = -1,DOWN = 1,LEFT = 2,RIGHT = 4,STOP} DIR;
DIR cur_dir = RIGHT;

struct termios oldTermios;
int oldFcntl;

typedef struct s_snake_note		//蛇身结点:包括坐标(x,y)和前进方向(dir)
{
	int x;
	int y;
	DIR dir;
}Snake_data;

typedef struct link_snake
{
	Snake_data data;
	struct link_snake *next;
}ls,*psnake;
psnake link_head,tail,snake_head;

typedef struct s_food
{
	int x;
	int y;
}Food,*pfood;
pfood food;

void init_food()	//初始化食物
{
	srand(time(NULL));
	food = (pfood)malloc(sizeof(pfood));
	food->x = 11 + rand()%(AREA_WIDHT - 2);
	food->y = 6 + rand()%(AREA_HIGHT - 2);
}

void display()		//游戏区域
{
	int i;
	MOVETO(10,5);
	printf("╔");
	MOVETO(11,5);
	for (i = 0; i < AREA_WIDHT-2; i++)
		printf("═");
	MOVETO(10+AREA_WIDHT-1,5);
	printf("╗");
	for (i = 1; i <= AREA_HIGHT-2; i++)
	{
		MOVETO(10,5+i);
		printf("║");
		MOVETO(10+AREA_WIDHT-1,5+i);
		printf("║");
	}
	MOVETO(10,AREA_HIGHT+4);
	printf("╚");
	MOVETO(11,AREA_HIGHT+4);
	for (i = 0; i < AREA_WIDHT-2; i++)
		printf("═");
	MOVETO(10+AREA_WIDHT-1,AREA_HIGHT+4);
	printf("╝");
	
	MOVETO(1,25);
}

void init_snake()	//初始化蛇身
{
	int i;
	psnake p;
	p = (psnake)malloc(sizeof(Snake_data));
	if (p == NULL)
	{
		printf("malloc fail (init_snake-if.1)\n");
		return;
	}
	p->data.x = 25;
	p->data.y = 13;
	p->data.dir = cur_dir;
	link_head = p;
	tail = p;
	for (i = 1; i <= snake_length - 1; i++)
	{
		p = (psnake)malloc(sizeof(Snake_data));
		if (p == NULL) 
		{
			printf("malloc fail (init_snake-if.2)\n");
			return;
		}
		p->data.x = 25 + i;
		p->data.y = 13;
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;		//链表尾部,"tail" 即为蛇头
	snake_head = tail;
}

void draw_snake_food()	//画蛇,食物
{
	psnake ps = link_head;
	MOVETO(snake_head->data.x,snake_head->data.y);		//用◆代替蛇头
	printf("◆");
	printf("\n");
	while (ps->next != NULL)			//用≈代表蛇身
	{
		MOVETO(ps->data.x,ps->data.y);
		printf("≈");
		printf("\n");
		ps = ps->next;
	}
	MOVETO(food->x,food->y);
	printf("✹");
	MOVETO(1,25);
	printf("\n");
}

int snake_move()	//蛇身移动
{
	int x,y,flag = 0;
	psnake p,b,f,old_link_head;
	p = link_head;		//用于移动
	b = link_head;		//用于判断是否撞到自己
	f = link_head;		//用于判断产生的食物是否与身体重合
	x = link_head->data.x;	//保存链表头坐标
	y = link_head->data.y;
	while (p != NULL && p->next != NULL)		//蛇身移动
		{
			p->data = p->next->data;
			p = p->next;
		}										//after this,p = snake_head,as tail
	if (cur_dir == RIGHT || cur_dir == LEFT)	//方向控制
		p->data.x += cur_dir -3;
	else
		p->data.y += cur_dir;
	if (p->data.x == 10 || p->data.x == 49 || p->data.y == 5 || p->data.y == 24)	//判断是否撞墙
	{
		MOVETO(23,13);
		printf("\033[0;31;24m");
		printf("You hit the wall!\n");
		printf("\033[0m");
		MOVETO(1,25);
		return 0;
	}
	while (b != NULL && b->next != NULL)		//b = link_head, 判断是否撞身体
	{
		if (p->data.x == b->data.x && p->data.y == b->data.y)
		{
			MOVETO(23,13);
			printf("\033[0;31;24m");
			printf("You hit yourself!\n");
			printf("\033[0m");
			MOVETO(1,25);
			return 0;
		}
			b = b->next;
	}
	if (p->data.x == food->x && p->data.y == food->y)		//吃到食物
	{
		score++;
		snake_length++;
		while(flag == 0)			//判断产生的食物是否与身体重合
		{
			food->x = 11 + rand()%(AREA_WIDHT - 2);
			food->y = 6 + rand()%(AREA_HIGHT - 2);
			while (f != NULL)		//f = link_head
			{
				if (food->x == f->data.x && food->y == f->data.y)
				{
					flag = 0;
					break;
				}
				f = f->next;
			}
			flag = 1;
		}
		old_link_head = (psnake)malloc(sizeof(psnake));
		if (NULL == old_link_head)
		{
			printf("malloc fail at snake_move(if-1)\n");
			return 1;
		}
		old_link_head->data.x = x;
		old_link_head->data.y = y;
		old_link_head->next = link_head;
		link_head = old_link_head;				//蛇身加 1 
	}
}

void RestoreConsole(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
	fcntl(STDIN_FILENO, F_SETFL, oldFcntl);
}

void PrepareConsole(void)
{
	tcgetattr(STDIN_FILENO, &oldTermios);
	struct termios newTermios = oldTermios;
	newTermios.c_lflag &= ~(ECHO | ICANON);
	oldFcntl = fcntl(STDIN_FILENO, F_GETFL);
	int newFcntl = oldFcntl | O_NONBLOCK;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &newTermios) == -1 || fcntl(STDIN_FILENO, F_SETFL, newFcntl) == -1) 
	{
		RestoreConsole();
		exit(-1);
	}
}

int Speed(int count)		//控制蛇的移速,每增长5分速度提升一次
{
	if (score == 0)
	{
		return count;
	}
	else if (score%5 != 0)
	{
		return count;
	}
	else if (score%5 == 0 && count > 1)
	{
		count = count - 1;
		return count;
	}
	else if (count == 1)
		return count;
}

void read_game()
{
	int n,t = 1;
	signed int read_dir;
	char buf[6];
	FILE *fp;
	if ((fp = fopen("information.dat","r")) == NULL)
	{
		init_food();
		init_snake();
		printf("open file fail,at read_information-if-1.\n");
		return;
	}
	if(fp)	fclose(fp);
	fp = fopen("information.dat","r");
	fread(buf,5,1,fp);
	if (strncmp(buf,"SNAKE",5) != 0)
	{
		init_food();
		init_snake();
	}
	else
	{
		fread (&ver,4,1,fp);
		if (ver == 1)
		{
			int i;
			fread (&snake_length,4,1,fp);
			fread (&read_dir,4,1,fp);
			psnake p,ptail;
			for (i = 0; i < snake_length; i++)
			{
				p = (psnake)malloc(sizeof(psnake));
				if (p ==NULL)
				{
					printf("malloc fail,at read_information\n");
					return;
				}
				fread(&p->data,sizeof(Snake_data),1,fp);
				if (t == 1)
				{
					link_head = p;
					ptail = p;
					t = 0;
				}
				else
				{
					ptail->next = p;
					ptail = p;
				}
			}
			ptail->next = NULL;
			snake_head = ptail;
			cur_dir = read_dir;
			food = (pfood)malloc(sizeof(pfood));
			fread(food,sizeof(pfood),1,fp);
			fread (&score,4,1,fp);
			fread (&speed,4,1,fp);			
		}
		else if (n == 1)
		{
			init_food();
			init_snake();
		}
	}
	fclose(fp);
	fp = NULL;
}

void save_game()
{
	FILE *fp;
	if ((fp = fopen("information.dat","w")) == NULL)
	{
		printf("open file fail,at read_information-if-1.\n");
		return;
	}
	fwrite("SNAKE",5,1,fp);
	fwrite(&ver,4,1,fp);
	fwrite(&snake_length,4,1,fp);
	fwrite (&cur_dir,4,1,fp);
	psnake p;
	p = link_head;
	while (p != NULL)
	{
		fwrite (&p->data,sizeof(Snake_data),1,fp);
		p = p->next;
	}
	fwrite (food,sizeof(pfood),1,fp);
	fwrite(&score,4,1,fp);
	fwrite(&speed,4,1,fp);
	fclose(fp);
	fp=NULL;
}

int stop_game()		//游戏暂停(可保存退出)
{
	char ch;
	MOVETO(11,3);
	printf("Game stoping,Press space to continu");
	while (1)
	{
		if ((ch = getchar()) == 'q')
		{
			MOVETO(1,25);
			save_game();
			RestoreConsole();
			return 0;
		}
		else if ((ch = getchar()) == ' ')
			return 1;
	}
}

int main()
{
	int t;
	read_game();
	PrepareConsole();
	while(1)
	{
		t = Speed(speed);
		int c = EOF, ch = EOF;
		while ((c = getchar()) != EOF)
		{
			ch = c;
		}
		switch(ch)
		{
			case 'w':	cur_dir = UP;	 break;
			case 's':	cur_dir = DOWN;	 break;
			case 'a':	cur_dir = LEFT;	 break;
			case 'd':	cur_dir = RIGHT; break;
			case 'q':	save_game();	 RestoreConsole();	return 0;
			case ' ':	if (stop_game())
							break;
						else
							return 0;
		}
		display();
		system("clear");
		MOVETO(42,4);
		printf("speed: %d",8-t);
		MOVETO(10,4);
		printf("score: %d",score);
		if (snake_move() == 0)
			break;
		draw_snake_food();
		usleep(100000*t);
	}
	RestoreConsole();
	return 0;
}
