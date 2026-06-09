#include<stdio.h>
#include<unistd.h>

int main(void)
{
	printf("program started !!!\n");
	int ret = fork();
	printf("Return value : %d\n", ret);
	printf("program finished !!!\n");
	return 0;
}
