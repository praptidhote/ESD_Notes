#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int sig)
{
	if(sig == SIGINT)
		printf("SIGINT signal is caught : %d\n", sig);
	else if(sig == SIGTERM)
		printf("SIGTERM signal is caught : %d\n", sig);
	else if(sig == SIGALRM)
		printf("SIGALRM signal is caught : %d\n", sig);
	else
		printf("signal is caught : %d\n", sig);
}

void sigsegv_handler(int sig)
{
	printf("SIGSEGV signal is caught : %d\n", sig);
	_exit(1);
}

int main(void)
{
	int i = 0;

	signal(SIGINT, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGALRM, sig_handler);
	signal(SIGSEGV, sigsegv_handler);

	while(1)
	{
		printf("i = %d\n", i++);
		sleep(2);
	}

	return 0;

}
	

