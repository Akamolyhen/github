//myfile.c
#include <stdlib.h>
#include <stdio.h>
#include "myfile.h"

 
void changMyTxtFile()
{
	FILE *pfw;
	int s;
	int num=1;
	pfw=fopen("记录信息\\mytxt.txt","w");
	if (pfw==NULL)
	{
		printf("文件操作失败");
		return;
	}
	while(s=getchar(),s!=-1)
	{
		fprintf(pfw,"%c",s);
	}
	fclose(pfw);
}
void showMyTxtFile()
{
	FILE *pfr;
	pfr=fopen("记录信息\\mytxt.txt","r");
	if (pfr==NULL)
	{
		printf("文件操作失败");
		return ;
	}
	else 
	{	
		while (!feof(pfr))
		{
			char str[256] = {0};			
			fgets(str, 256, pfr);          //动态  遍历文件
			puts(str);
		}
	}
	fclose(pfr);
}
 
void showBianMaFile()
{
	FILE *pfr;
	pfr=fopen("记录信息\\编码.txt","r");
	if (pfr==NULL)
	{
		printf("文件操作失败");
		return ;
	}
	else 
	{	
		while (!feof(pfr))
		{
			char str[256] = {0};			
			fgets(str, 256, pfr);
			puts(str);
		}
	}
	fclose(pfr);
}
 
void showYiMaFile()
{
	FILE *pfr;
	pfr=fopen("记录信息\\译码.txt","r");
	if (pfr==NULL)
	{
		printf("文件操作失败");
		return ;
	}
	else 
	{	
		while (!feof(pfr))
		{
			char str[256] = {0};			
			fgets(str, 256, pfr);
			puts(str);
		}
	}
	fclose(pfr);
}
 
void changBianMaFile()
{
	
	FILE *pfw;
	int s;
	pfw=fopen("记录信息\\编码.txt","w");
	if (pfw==NULL)
	{
		printf("记录信息\\文件操作失败");
		return ;
	}
	while(s=getchar(),s!=-1)
	{
		fprintf(pfw,"%c",s);
	}
	fclose(pfw);
	
}