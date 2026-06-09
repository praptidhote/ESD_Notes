#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("program started !!!\n");
	int ret = fork();
	printf("Return value : %d\n", ret);
	printf("pid = %d, ppid = %d\n", getpid(), getppid());
	printf("program finished !!!\n");
	sleep(2);
	return 0;
}
