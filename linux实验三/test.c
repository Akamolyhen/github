#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int IsLeapYear()
{
	int year = 0;
	printf("Please enter the year:\n");
	scanf("%d", &year);
	if (year < 0)
	{
		return -1;
	}
	else if (((year% 100 != 0) && (year % 4 == 0)) || (year % 400 == 0))
	{
		printf("Is\n");
		return 0;
	}
	else
	{
		printf("Not\n");
		return 0;
	}
}
int GreatCommonDivisor()
{
	int a, b, yu, m, n;
	printf("Input two numbers:\n");
	scanf("%d %d", &m, &n);
	a = m;
	b = n;
	while (a%b != 0)
	{
		yu = a % b;
		a = b;
		b = yu;
	}
	printf("Great Common Divisor Is %d\n", b);
	return 0;
}
int Date_of_calculation()
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);
	printf("%d-%d-%d\t", 1900 + p->tm_year,1 + p->tm_mon, p->tm_mday);
	printf("%02d:%02d:%02d\n",8 + p->tm_hour,p->tm_min, p->tm_sec);

	return 0;
}

int main()
{
	pid_t child1,child2,child3;
	child1=fork();
	if(child1<0)
	{
		perror("fork");
	}
	else if(child1==0){
		printf("我是执行最大公约数！\n");
		GreatCommonDivisor();
	}
	else{
		child2=fork();
		if(child2<0)
	{
		perror("fork");
	}
	else if(child2==0){
		printf("我是执行是否为闰年！\n");
		IsLeapYear();
	}
	else{
		child3=fork();
		if(child3<0)
	{
		perror("fork");
	}
	else if(child3==0){
		printf("我是执行计算时间！\n");
		Date_of_calculation();
	}
	else{
		printf("程序结束！\n");
		
	}
	}
	}
	return 0;

}