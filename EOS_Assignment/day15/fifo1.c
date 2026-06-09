#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(void)
{
	int fd = open("/home/sunbeam/Desktop/EOS_Assignment/day15/myfifo", O_RDONLY);

	char str1[64];
	printf("p1 [%d]: waiting for a message....\n", getpid());
	read(fd, str1, sizeof(str1));
	printf("p1 [%d]: received message : %s\n", getpid(), str1);

	close(fd);

	return 0;
}
