#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	printf("program started !!!\n");
	int ret = fork();
	if(ret == -1)
	{
		printf("fork() is failed\n");
		exit(-1);
	}
	else if(ret == 0)
	{
		printf("child : return value : %d\n", ret);
		printf("child : pid = %d, ppid = %d\n", getpid(), getppid());
	}
	else
	{
		printf("Parent : Return value :%d\n", ret);
		printf("Parent : pid = %d, ppid = %d\n", getpid(), getppid());
	}
	printf("program finished !!!\n");
	sleep(2);
	return 0;
}
