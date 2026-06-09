#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

void sigint_handler(int sig, siginfo_t*info, void *ptr)
{
	printf("signal sent by process with PID = %d\n", info->si_pid);
	for(int i =1 ; i <= 5 ; i++)
	{
		printf("[%d] i = %d\n", getpid(), i);
		sleep(1);
	}
}

int main(void)
{
	struct sigaction sa;
	memset(&sa, sizeof(sa), 0);

	sa.sa_sigaction = sigint_handler;
	sa.sa_flags = SA_SIGINFO;
	sigfillset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);

	int j = 0;
	while(1)
	{
		printf("[%d] j = %d\n", getpid(), j++);
		sleep(2);
	}
	
	return 0;
}
