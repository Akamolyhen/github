#include<stdio.h>
#include<unistd.h>
 int main(void)
{
    pid_t pid=0;
    int pfd[2];
    char buf1[128]={"this is data from fprocess"};
    char buf2[128];
    if(pipe(pfd)<0)
       {
           perror("creatpipe fault!\n");
           exit(1);
           }
    pid=fork();
       if(pid>0)
       {
           write(pfd[1],buf1,128);
           wait();
           close(pfd[1]);
           exit(0);
           }
          else
           {
           read(pfd[0],buf2,128);
           printf("%s\n",buf2);
           close(pfd[0]);
           exit(0);
              }
    return 0;
 }

