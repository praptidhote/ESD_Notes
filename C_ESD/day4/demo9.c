#include<stdio.h>

int main()
{

	int row = 4 , col = 4;
	int i ,j;

	int k;
	for(i = 1; i <= row ; i++)
	{
		for(j = row -i ; j>= 1 ; j--)
		{
			printf(" ");
		}
		for(k = 1 ; k <= i ; k++)
		{
			printf(" * ");
		}
		printf("\n");
	}
	return 0;
}
