#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
	printf("Program started \n");
	int arr[2];
	pipe(arr);

	int pid = fork();
	if(pid == 0)
	{
		close(arr[0]);
		char str1[64];
		printf("child : enter message : ");
		scanf("%[^\n]s", str1);
		write(arr[1], str1, strlen(str1)+1);
		printf("child : message written to pipe\n");
		close(arr[1]);
		_exit(0);
	}
	else
	{
		close(arr[1]);
		char str2[64];
		printf("parent : waiting for a message ...\n");
		read(arr[0], str2, sizeof(str2));
		printf("parent : Received message = %s\n", str2);
		close(arr[0]);
	}
	
	int s;
	wait(&s);

	printf("program finished \n");
	return 0;
}

