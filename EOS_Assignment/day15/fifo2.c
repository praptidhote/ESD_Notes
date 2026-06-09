#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(void)
{
	int fd = open("/home/sunbeam/Desktop/EOS_Assignment/day15/myfifo", O_WRONLY);
	char str1[64];
	printf("p1 [%d]: Enter message : ", getpid());
	scanf("%[^\n]s", str1);
	write(fd, str1, strlen(str1)+1);
	printf("p1 [%d]: message written to pipe\n", getpid());
	close(fd);

	return 0;
}
