#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(void)
{
	printf("Program started \n");
	int pid = fork();
	if(pid == 0)
	{
		int ofd = open("output.txt", O_CREAT | O_TRUNC | O_WRONLY, 0664);
		close(1);
		dup(ofd);
		close(ofd);

		int efd = open("error.txt", O_CREAT | O_TRUNC | O_WRONLY, 0664);
		dup2(efd, 2);
		close(efd);

		char *argv[] = {"ls", "-l", "/home", "/xyz", NULL};
		int ret = execvp("ls", argv);
		if(ret == -1)
		{
			printf("execvp() is failed\n");
			_exit(-1);
		}
	}
	else
	{
		int s;
		waitpid(pid, &s, 0);
	}
	printf("program finished \n");
	return 0;
}

