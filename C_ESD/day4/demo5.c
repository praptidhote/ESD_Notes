#include<stdio.h>

int main()

{

	int num1;
	printf("enter the num : ");
	scanf("%d",&num1);

	int i = 1;

	while(i <= 10 )
	{
		printf("%d\n %d\n %d \n", i + num1, i * num1, i - num1);

		i++;
	}

	return 0;

}
