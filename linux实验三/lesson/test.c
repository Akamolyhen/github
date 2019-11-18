#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
        pid_t pid;
        if((pid=fork())==-1)
                printf("fork error\n");
        printf("a example of fork,pid = %d\n",getpid());
        return 0;
}
