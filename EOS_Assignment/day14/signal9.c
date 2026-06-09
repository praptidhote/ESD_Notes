#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int sig)
{
	printf("%d signal is caught [ PID = %d]\n", sig, getpid());
}

int main(void)
{

	sigset_t set;
	sigemptyset(&set);

	sigaddset(&set, SIGTERM);
	sigaddset(&set, SIGALRM);
	
	int ret = sigprocmask(SIG_SETMASK, &set, NULL);
	if(ret == -1)
	{
		printf("sigprocmask() is failed\n");
		_exit(ret);
	}

	struct sigaction sa;

	memset(&sa, sizeof(sa), 0);
	sa.sa_handler = sig_handler;
	ret = sigaction(SIGTERM, &sa, NULL);
	if(ret == -1)
	{
		printf("sigaction() for SIGTERM is failed\n");
		_exit(ret);
	}
	
	ret = sigaction(SIGALRM, &sa, NULL);
	if(ret == -1)
	{
		printf("sigaction() for SIGTERM is failed\n");
		sleep(2);
	}
	return 0;
}
