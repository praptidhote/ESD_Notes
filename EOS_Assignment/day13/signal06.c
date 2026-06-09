#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
	printf("SIGINT signal is caught : %d\n", sig);
}

int main(void)
{
	int i = 0;
	struct sigaction sa;
	sa.sa_handler = sigint_handler;

	sigaction(SIGINT, &sa, NULL);

	while(1)
	{
		printf("i = %d\n", i++);
		sleep(2);
	}

	return 0;
}
