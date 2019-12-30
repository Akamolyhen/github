
#include 	"snake_info.h"


SNK_DIR 	snk_dir; //保存蛇移动的方向

PBody 		head; //链表头指针

sem_t 		sem;  //信号量，控制蛇的移动


sem_t 		sem_food; //信号量，控制投食
Body 		food; //保存食物的坐标
int		eat_flag; //0没吃  1:吃到
static int 	n_times = 0; //记录定时器的次数，用于二次定时--》刷食物的时间间隔

int 		speed; //蛇的移动速度

pthread_rwlock_t 	dir_lock; //读写 snk_dir 锁保护
pthread_mutex_t 	food_lock; //读写 food / eat_flag锁保护

pthread_mutex_t	 	lcd_mut; //保护屏幕读写 锁

pthread_mutex_t	 	n_times_mut; //保护屏幕读写 锁




/*--------------------------------- 蛇身相关的链表操作 ---------------------------- */

void  list_init(void){
	
	head = calloc(1, sizeof(Body) );
	head->next = head->prev = head;
	return ;
}


void list_add_head(PBody new){
	
	new->next = head->next;
	new->prev = head;
	head->next->prev = new;
	head->next = new;
}

void list_add(PBody new){
	
	PBody tmp;

	new->prev = head->prev;
	new->next = head;
	
	head->prev->next = new;
	head->prev = new;
}

void list_free(){
	
	PBody tmp;
	
	for( tmp = head->next;  tmp != head; tmp = head->next){
		
		head->next = tmp->next;
		tmp->next->prev = head;
		free( tmp );
		
	}
	
	free(head);
}

bool list_seek(int x, int y){
	
	PBody tmp=head;
	if(tmp->x == x && tmp->y == y)return true;
	
	for( tmp = tmp->next ; tmp!=head; tmp = tmp->next){
		if(tmp->x == x && tmp->y == y)return true;
	}
	
	return false;
}

void list_pri(){
	
	PBody tmp=head;
	printf("(%d,%d)\t",tmp->x,tmp->y);
	
	for( tmp = tmp->next ; tmp!=head; tmp = tmp->next){
		printf("(%d,%d)\t",tmp->x,tmp->y);
	}
	puts("");
}



/*--------------------------------- 蛇身的移动操作 ---------------------------- */
void mk_dxy(int *dx, int *dy, SNK_DIR snk_dir){
	
	*dx = *dy = 0;
	
	pthread_rwlock_rdlock(&dir_lock);
	switch(snk_dir){
		
	case LEFT:
		*dx = -32; break;
	case RIGHT:
		*dx = 32; break;
	case UP:
		*dy = -32;break;
	case DOWN:
		*dy = 32; break;
		
	}
	pthread_rwlock_unlock(&dir_lock);


}


void snake_init(void){
	
	//链表初始化
	list_init();
	
	//初始化蛇头坐标 并显示
	head->x = (rand()%150+150)/32 * 32;
	head->y = (rand()%150+150)/32 * 32;
	bmp_show(H_PIC, head->x, head->y);
	
	//初始化移动方向
	snk_dir = rand()%4 + 1;
	
	//初始化剩余的两个蛇身并 显示
	for( int i=0 ; i<2; i++){
		int dx=0,dy=0;
		PBody new = calloc(1, sizeof(Body));
		mk_dxy(&dx,&dy,snk_dir); //根据方向计算增量
		new->x = head->prev->x - dx;
		new->y = head->prev->y - dy;
		
		list_add(new );
		
		bmp_show(S_PIC, new->x, new->y);
	}
	
	//初始化信号量
	sem_init( &sem, 0, 0);
	sem_init( &sem_food, 0, 1);
	

	
	//初始化 dir 读写锁
	pthread_rwlock_init(&dir_lock, NULL);
	
	//初始化 lcd 互斥锁
	pthread_mutex_init( &lcd_mut, NULL);
	
	//初始化 food 互斥锁
	pthread_mutex_init(&food_lock, NULL);
	
	//初始化 n_times_mut 互斥锁
	pthread_mutex_init(&n_times_mut, NULL);
	
	
	return ;
	
}


void set_speed(void){
	
	struct itimerval new_value = {{0,(900-speed*165)*1000},{0,(900-speed*165)*1000}};
	setitimer(ITIMER_REAL,  &new_value,NULL);
	
	char path[100] = {0};
	
	sprintf(path,"%s/%d.bmp",PATH_PRE, speed+1);
	
	pthread_mutex_lock( &lcd_mut);
	bmp_show(path, 750,190);
	pthread_mutex_unlock( &lcd_mut);
}


//定时器的信号函数
void alarm_handler(int sig){
	
	
	sem_post(&sem);
	
	
	pthread_mutex_lock(&n_times_mut);
	if(++n_times>=12){
		n_times=0;
		sem_post(&sem_food);
	}
	pthread_mutex_unlock(&n_times_mut);
}


//控制蛇的移动 线程
void *  move_routine(void * arg){
	
	
	int dx=0,dy=0; //保存移动增量
	
	//初始化蛇的速度
	speed = 0;
	signal(SIGALRM, alarm_handler);
	set_speed();
	
	while(1){
		
		sem_wait(&sem); //等待信号量 ， 移动
		
		PBody tmp = head->prev;
		
		//lcd 访问加锁保护
		{
		
			mk_dxy(&dx,&dy,snk_dir); //获取移动的增量
			
			//判断是否撞到自己
			if(list_seek(head->x + dx, head->y + dy)){
				puts("game over");
				raise(SIGINT);
				pthread_exit(NULL);
			}
		
			//判断是否吃到食物
			if(head->x + dx == food.x &&  head->y + dy == food.y){
				pthread_mutex_lock(&food_lock);
				eat_flag = 1;
				pthread_mutex_unlock(&food_lock);
				
				//吃到则用食物的坐标 增加新头
				tmp = calloc(1,sizeof(Body));
				pthread_mutex_lock(&food_lock);
				tmp->x = food.x, tmp->y = food.y;
				list_add(tmp);
				pthread_mutex_unlock(&food_lock);
				
				//通知食物线程，重新投食
				struct itimerval new_value = {{0,(900-speed*165)*1000},{0,(900-speed*165)*1000}};
				setitimer(ITIMER_REAL,  &new_value,NULL);
				sem_post(&sem_food);
				pthread_mutex_lock(&n_times_mut);
				n_times = 0;
				pthread_mutex_unlock(&n_times_mut);
				
				
			}else{ //没吃到 --> 把最后一个变为新的头
				
				pthread_mutex_lock( &lcd_mut);
				bmp_show_bck( tmp->x, tmp->y, 32, 32);
				pthread_mutex_unlock( &lcd_mut);
		
				tmp->x = head->x + dx;
				tmp->y = head->y + dy;	

				//越界判断
				if(tmp->x < 0 )tmp->x = 576;
				else if( tmp->x > 576)tmp->x = 0;

				if(tmp->y < 0 )tmp->y = 448;
				else if( tmp->y > 448)tmp->y = 0;				
			}

			//旧的头刷成身子
			pthread_mutex_lock( &lcd_mut);
			bmp_show(S_PIC, head->x, head->y);
			pthread_mutex_unlock( &lcd_mut);			
			
			//加新头
			head = tmp;
			pthread_mutex_lock( &lcd_mut);
			bmp_show(H_PIC, head->x, head->y); 
			pthread_mutex_unlock( &lcd_mut);
		}
		

	}
	
}



void * touch_routine(void * arg){
	
	int x, y;
	
	while(1){
		SNK_DIR flag = NONE;
		int sc = 0; //speed change
		get_xy( &x, &y);
		
		if( x>610 && x<685 && y>365 && y<410){//left
			if(snk_dir!=RIGHT)flag = LEFT;	
		}else if(x>720  && y>365 && y<410){//right
			if(snk_dir!=LEFT)flag = RIGHT;
		}else if(x>670 && x<730 && y>315 && y<380){//UP
			if(snk_dir!=DOWN)flag = UP;
		}else if(x>670 && x<730 && y>400 && y<450){//DOWN
			if(snk_dir!=UP)flag = DOWN;
		}
		
		//加信号量移动蛇  并重新倒计时
		if(flag != NONE){
			
			pthread_rwlock_wrlock(&dir_lock);
			snk_dir = flag;
			pthread_rwlock_unlock(&dir_lock);
			
			sem_post(&sem); 
			struct itimerval new_value = {{0,(900-speed*165)*1000},{0,(900-speed*165)*1000}};
			setitimer(ITIMER_REAL,  &new_value,NULL);			
		}
		
		if( x>630 && x<705 && y>215 && y<285){//speed +
		
			if(++speed, speed > 4)speed = 4;
			sc = 1;
			
			
		}else if( x>720  && y>215 && y<285){//speed -
		
			if(--speed, speed < 0)speed = 0;
			sc = 1;
			
		}
		
		if(sc){ //需要修改 刷新速度
			set_speed();
		}
		
		
	}
	
}


void * mk_food(void * arg){
	
	eat_flag = 0;
	while(1){
		
		sem_wait(&sem_food); //等待投食信号量
		
		
		if(eat_flag == 0){   //没吃到食物 则清除之前的食物
			
			pthread_mutex_lock( &lcd_mut);
			bmp_show_bck( food.x, food.y, 32, 32);
			pthread_mutex_unlock( &lcd_mut);
		}else{
			//清除 吃 标识
			pthread_mutex_lock(&food_lock);
			eat_flag = 0;
			pthread_mutex_unlock(&food_lock);
		}
		
		//重新投食
		bool seek;
		do{
			pthread_mutex_lock(&food_lock);
			
			food.x = (rand()%576)/32 * 32;
			food.y = (rand()%448)/32 * 32;
			seek = list_seek(food.x, food.y);
			
			pthread_mutex_unlock(&food_lock);
			
		}while(seek==true);
		
		
		pthread_mutex_lock( &lcd_mut);
		bmp_show(H_PIC, food.x, food.y);
		pthread_mutex_unlock( &lcd_mut);

		
	}
	
}
