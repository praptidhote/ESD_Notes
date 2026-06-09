#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

void sig_handler(int sig)
{
	printf("%d signal is caught [ PID = %d]\n", sig, getpid());
}

int main(void)
{
	struct sigaction sa;

	memset(&sa, sizeof(sa), 0);
	sa.sa_handler = sig_handler;
	int ret = sigaction(SIGINT, &sa, NULL);
	if(ret == -1)
	{
		printf("sigaction() for SIGINT is failed\n");
		_exit(ret);
	}

	ret = sigaction(SIGTERM, &sa, NULL);
	if(ret == -1)
	{
		printf("sigaction() for SIGTERM is failed\n");
		_exit(ret);
	}
	
	sigset_t mask;
	
	sigfillset(&mask);
	sigdelset(&mask, SIGINT);
	sigdelset(&mask, SIGSEGV);
	sigdelset(&mask, SIGALRM);

	printf("waiting for either SIGINT, SIGSEGV or SIGALRM.....\n");
	sigsuspend(&mask);
	printf("bye\n");

	return 0;
}
