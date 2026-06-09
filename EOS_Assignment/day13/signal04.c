#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void sigchld_handler(int sig)
{
	int status;
	printf("SIGCHLD signal is caught : %d\n", sig);
	wait(&status);
	printf("exit status of child = %d\n", WEXITSTATUS(status));
}

int main(void)
{
	int ret;
	printf("program started !!!\n");

	signal(SIGCHLD, sigchld_handler);
	ret = fork();
	if(ret == 0)
	{
		for(int i = 1 ; i <= 10 ; i++)
		{
			printf("child (%d) : i = %d\n", getpid(), i);
			sleep(1);
		}
	
	}
	else
	{
		for(int i = 15 ; i >= 1 ; i--)
		{
			/*
			if(i == 5)
			{
				wait(&status);
				printf("exit status of child = %d\n", WEXITSTATUS(ststus));
			}
			*/

			printf("parent (%d) : i = %d\n", getpid(), i);
			sleep(1);

		}
	}
	printf("program finished !!!\n");
	return 0;
}

