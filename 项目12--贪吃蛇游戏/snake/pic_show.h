#ifndef 		__PIC_SHOW_H
#define 		__PIC_SHOW_H



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
#include 	  <linux/input.h> //触摸屏


#define		PATH_PRE	"./SNK_pic/"
#define		H_PIC		"./SNK_pic/h.bmp"
#define		S_PIC		"./SNK_pic/s.bmp"
#define		BCK_PIC		"./SNK_pic/snake.bmp"



int 	bmp_show(char * pic_path, int x0, int y0);
void 	lcd_init(void);
void 	lcd_free(void);
int 	bmp_show_bck(int x0, int y0, int W, int H);
void  	get_xy( int * x, int *y);


#endif
