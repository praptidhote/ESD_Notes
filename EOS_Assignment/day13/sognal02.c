#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sigint_handler(int sig)
{
	printf("SIGNT signal is caught : %d\n", sig);
}

void sigterm_handler(int sig)
{
	printf("SIGTERM signal is caught : %d\n", sig);
}

void sigalrm_handler(int sig)
{
	printf("SIGALRM signal is caught : %d\n", sig);
}

void sigsegv_handler(int sig)
{
	printf("SIGSEGV signal is caught : %d\n", sig);
	_exit(1);
}

int main(void)
{
	int i = 0;

	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	signal(SIGALRM, sigalrm_handler);
	signal(SIGSEGV, sigsegv_handler);

	while(1)
	{
		printf("i = %d\n", i++);
		sleep(2);
	}

	return 0;
}
