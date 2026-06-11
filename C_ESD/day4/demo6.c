#include<stdio.h>

int main()
{

	int num, rem, rev = 0;

	printf("enter the num : ");
	scanf("%d",&num);

	int temp = num;

	while( num != 0 )
	{
		rem = num % 10;
		rev = rev * 10 + rem;

		num = num / 10;
	}

	if(rev == temp)
		printf("num is palindrome : %d \n",temp);
	else
		printf("num is not palindrome : %d \n",temp);
	return 0;

}
