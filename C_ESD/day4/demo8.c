#include<stdio.h>

int main()
{

	int base, index, pow = 1;
	printf("enter the base : ");
	scanf("%d",&base);

	printf("enter the index : ");
	scanf("%d",&index);

	int i;

	for( i= 1; i<= index ; i++)
	{
	 pow = pow * base;
	}

	printf("%d ^ %d : %d \n", base,index, pow );

	return 0;
}

