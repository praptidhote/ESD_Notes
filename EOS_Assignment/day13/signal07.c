#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

void sigchld_handler(int sig, siginfo_t *info, void*ptr)
{
	int status;
	printf("SIGCHLD signal is caught : %d\n", info->si_pid);
	printf("signal is send by PID = %d\n", info->si_pid);
	wait(&status);
	printf("exit status of child = %d\n", WEXITSTATUS(status));
}

int main(void)
{
	int ret;
	printf("program started !!!\n");

	struct sigaction sa, old_sa;
	memset(&sa, sizeof(struct sigaction), 0);
	sa.sa_sigaction = sigchld_handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGCHLD, &sa, &old_sa);

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
			printf("parent (%d) : i = %d\n", getpid(), i);
			sleep(1);
		}
	}
	printf("program finished !!!\n");
	return 0;
}
