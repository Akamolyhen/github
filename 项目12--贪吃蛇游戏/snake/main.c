#include 	"pic_show.h"
#include 	"snake_info.h"

pthread_t 	tid_move; //蛇移动线程号
pthread_t 	tid_touch; //触摸控制线程号
pthread_t 	tid_food; //投食线程号


void sig_hander(int sig){
	
	pthread_cancel(tid_move);
	pthread_cancel(tid_touch);
	pthread_cancel(tid_food);

	//接合3个线程
	pthread_join(tid_move, NULL);
	pthread_join(tid_touch, NULL);
	pthread_join(tid_food, NULL);
	
	lcd_free();
	list_free();	
	exit(1);
}



int main(int argc,char **argv)
{
	//初始化随机数发生器
	srand(time(NULL));
	
	//初始化LCD 
	lcd_init();
	
	//绑定ctrl+c 强制退出信号
	signal(SIGINT, sig_hander);

	//显示背景图片
	bmp_show(BCK_PIC, 0, 0);

	//蛇身的初始化
	snake_init();

	
	//创建自动移动线程
	pthread_create(&tid_move,NULL,move_routine, NULL);
	
	//创建触摸控制线程
	pthread_create(&tid_touch,NULL,touch_routine, NULL);
	
	//创建投食线程
	pthread_create(&tid_food,NULL,mk_food, NULL);
	
	
	
	//接合两个线程
	pthread_join(tid_move, 	NULL);
	pthread_join(tid_touch, NULL);
	pthread_join(tid_food, 	NULL);
	
	//释放资源
	lcd_free();
	list_free();
	
	return 0;
}//end of te main


