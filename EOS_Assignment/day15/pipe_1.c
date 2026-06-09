#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(void)
{
	int arr[2];
	char buf1[64] = "God Bless you !!!", buf2[64];
	int ret = pipe(arr);
	if(ret == -1)
	{
		printf("pipe is not created\n");
		_exit(ret);
	}
	write(arr[1],buf1, 64);
	printf("Data written into a pipe = %s\n", buf1);
	read(arr[0], buf2, 64);
	printf("Received data from pipe = %s\n", buf2);
	close(arr[0]);
	close(arr[1]);
	return 0;
}
