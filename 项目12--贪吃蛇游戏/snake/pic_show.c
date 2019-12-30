#include 	"pic_show.h"


static  int fd_lcd;
static  uint8_t * fp;
unsigned char * bck_info;

void lcd_init(void){
	
	//1. 打开LCD屏
 	fd_lcd  = open( "/dev/fb0", O_RDWR );
	if(fd_lcd == -1){
		perror(" open lcd ");
		exit(-1);
	}	


	//2. 做屏幕映射
	fp = mmap( NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, fd_lcd, 0);
	if( fp == (void*)-1){
		perror("mmap");
		close(fd_lcd);
		exit(-1);
	}	
	
	//3. 准备好背景图片的像素缓冲区
	int fd_bmp  = open( BCK_PIC, O_RDONLY );
	if(fd_bmp == -1){
		perror("open bmp");
		exit(-1);
	}
	
	bck_info = calloc( 800 * 480, 3); //图片像素点个数：width*height  每个像素点: 3个字节
	lseek(fd_bmp, 54, SEEK_SET); //跳过头信息
	read( fd_bmp, bck_info, 800 * 480 * 3); //读取颜色信息
	close(fd_bmp);
}


void lcd_free(void){
	close(fd_lcd);
	munmap(fp, 800*480*4);
	free(bck_info);
}


int bmp_show(char * pic_path, int x0, int y0){

	//0. 判断参数合法性
	if( x0 <0 || x0 >= 800  || y0<0 || y0>=480){
		fprintf(stderr, "显示图片位置有误\n");
		return -1;
	}


	//1. 打开BMP图片
	int fd_bmp  = open( pic_path, O_RDONLY );
	if(fd_bmp == -1){
		perror("open bmp");
		return -1;
	}

	//2. 存放 BMP像素
	int width, height;
	lseek( fd_bmp, 18, SEEK_SET);//跳到存放宽度的 位置
	read( fd_bmp, &width, 4); 
	read( fd_bmp, &height, 4);
	// printf ( "width:%d   height:%d\n", width, height );
	

	unsigned char * bmp_info = calloc( width * height, 3); //图片像素点个数：width*height  每个像素点: 3个字节
	lseek(fd_bmp, 54, SEEK_SET); //跳过头信息
	read( fd_bmp, bmp_info, width*height*3); //读取颜色信息


	//3. 颜色数据 写入 映射区
	for(int j=0; j<height && j<480-y0; j++){
		for(int i=0; i<width && i<800-x0; i++){

			memcpy( fp+ ( (j+y0)*800+ (i+x0))*4, bmp_info+ ((height-1-j)*width+i)*3, 3);
		}
	}


	//4. 释放资源
	close( fd_bmp);
	free( bmp_info);

	return 0;

}


int bmp_show_bck(int x0, int y0, int W, int H){

	//0. 判断参数合法性
	if( x0 <0 || x0 >= 800  || y0<0 || y0>=480){
		fprintf(stderr, "显示图片位置有误\n");
		return -1;
	}


	//1. 颜色数据 写入 映射区
	for(int j=y0; j<480 && j<y0+H; j++)
		for(int i=x0; i<800 && i<x0+W; i++){
			
			memcpy( fp+ ( j*800+ i)*4, bck_info+ ((479-j)*800+i)*3, 3);
			
		}
	

	return 0;
}






void  get_xy( int * x, int *y){
	
	
	struct input_event  in_evt;
	
	//1. 打开输入类 设备文件 --> 键盘  、 触摸屏
	int fd = open( "/dev/input/event0" , O_RDONLY);
	if( fd == -1){
		perror("open input dev");
		return ;
	}

	//2. 循环读取 设备发生的值
	while(1){

		read(fd, &in_evt, sizeof( in_evt) );
		
//		printf ( "type:0x%x  code:%d  value:%d\n", in_evt.type, in_evt.code , in_evt.value );

		if( in_evt.type == 0x03 && in_evt.code == 0){
			*x = in_evt.value;
		}else if( in_evt.type == 0x03 && in_evt.code == 1){
			*y = in_evt.value;
		}
		
		if(in_evt.code == 330 && in_evt.value == 0){
			break;
		}

	}
	
	close(fd);

	return ;
}


