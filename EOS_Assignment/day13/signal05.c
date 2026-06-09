#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
	printf("SIGINT signal is handled [PID = %d] : %d\n", getpid(), sig);
}

int main(void)
{
	int i = 0;
	signal(SIGINT, sigint_handler);

	while(1)
	{
		printf("[PID = %d] i = %d\n", getpid(), i++);
		sleep(2);
	}
	return 0;
}

