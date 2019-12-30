#ifndef 		__SNAKE_INFO_H
#define 		__SNAKE_INFO_H



/********std header**********/
#define           _PG_std
#include          <stdio.h>
#include          <stdlib.h>
#include          <stdint.h>
#include          <string.h>
#include          <strings.h>
#include          <math.h>
#include          <sys/mman.h>
#include          <errno.h>
#include          <stdarg.h>
#include          <time.h>
#include          <stdbool.h>



/**********IO header*************/
#define           _PG_IO
#include          <unistd.h>
#include          <sys/types.h>
#include          <sys/stat.h>
#include          <fcntl.h>
#include          <dirent.h>

/**********pthread header*************/
#define           _PG_thread
#include          <pthread.h>
#include          <sys/stat.h>
#include          <fcntl.h>
#include          <semaphore.h>
#include          <signal.h>

#include 	  <sys/time.h>


#include 	"pic_show.h"


typedef struct _body{
	
	int   x, y;
	
	struct _body * next, *prev;
	
}Body, *PBody ;

typedef enum _dir{
	NONE=0,LEFT = 1, RIGHT, UP, DOWN,
}SNK_DIR;


void  	list_free( void );
bool 	list_seek(int x, int y);


void  	snake_init(void);
void *  move_routine(void * arg);
void * 	touch_routine(void * arg);
void * 	mk_food(void * arg);

#endif
