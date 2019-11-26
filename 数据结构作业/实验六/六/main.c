//main.c
#include <stdlib.h>
#include <stdio.h>
#include "HuffmanTree.h"
#include "myfile.h"
 
 
#define MYHFMNUM 26*2+2
 
int  main()
{
	   HuffmanTree HT;
	   HuffmanCode HC;
	   int w[MYHFMNUM]={0},n=MYHFMNUM,i;
	   char s[MY_STRMAX]={0};
	   int num;
		system("color 3e");    //改颜色
MENU:
			system("cls");
	   puts("***********************************************");
	   puts("		1.创建新的编码");
	   puts("		2.编码");
	   puts("		3.译码");
	   puts("		4.退出");
	   puts("***********************************************");
 
	   puts("输入想要的操作:");
       scanf("%d",&num);
	   switch(num)
	   {
	   case 1: 
		   {	 FILE *pfw;	
			   system("cls");	 //每次操作清理屏幕
				puts("输入一段字符串，会根据字符数累加权值，从而生成树");
			   changMyTxtFile();
			   getWeightInfile(w);
			   HuffmanCoding(&HT,&HC,w,n);
			   pfw=fopen("记录信息\\编码表.txt","w");
			   if (pfw==NULL)
			   {
				   printf("文件操作失败");
				   return 0;
				}
					fprintf(pfw,"       编码    字母      权值\n");  
			   for(i=1;i<=n;i++) //把生成的   编码表  存在文件中 便于对照
			   {             
				   fprintf(pfw,"%10s\t%c\t%2d\n",HC[i],HT[i].ch,HT[i].weight);   
			   }
 
			   fclose(pfw);
				system("pause");
			   goto MENU;
		   }
	   case 2: 
		   {	system("cls");
			   puts("输入要编码的字符串");
			   changMyTxtFile();
			   bianMaInFile(&HT,HC); 
			   showBianMaFile();
			   system("pause");
			   goto MENU;
		   }
	   case 3:
			{	system("cls");
			   puts("输入要译码的二进制数字");
			   changBianMaFile();
			   yimaInFile(&HT);
			   showYiMaFile();
				system("pause");    //暂停一下  相当于getch
			   goto MENU;
		   }
	   case 4:return 0;
	   default:puts("输入有误!");system("pause");goto MENU;           
	   }
	   
	   return  0;
}