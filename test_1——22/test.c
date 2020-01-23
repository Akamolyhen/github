#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    pid_t pid;
    int count=0;
    pid=fork();
    if(pid==0){
        count++;
        exit(0);
    }
    else
    count++;  
    printf("count=%d",count);
    return 0;      

}