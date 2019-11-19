#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t p1, p2, p3;
	int status1, status2, status3;
	p1 = fork();
	if (p1 < 0)
	{
		perror("fork");
		return -1;
	}
	else if(p1 == 0)
	{
		execl("./doc", "./doc", "NULL");
		sleep(200);
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	p2 = fork();
	if (p2 < 0)
	{
		perror("fork");
	}
	else if (p2 == 0)
	{
		execl("./ily", "./ily", "NULL");
		sleep(200);	
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	p3 = fork();
	if (p3 < 0)
	{
		perror("fork");
	}
	else if (p3 == 0)
	{
		execl("./gcd", "./gcd", "NULL");
		sleep(200);
		exit(0);
	}
	else
	{
		wait(NULL);
	}
	
	//waitpid(p1, &status1, 0);
	//waitpid(p2, &status2, 0);
	//waitpid(p3, &status3, 0);
	return 0;
}
