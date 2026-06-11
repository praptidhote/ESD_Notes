#include<stdio.h>

int main()
{
	int year;
	printf("enter the year : ");
	scanf("%d",&year);
                         
	if((year % 4 ==0 && year %100 != 0) || year % 400 == 0 )
	{
		printf(" leap year : %d -> 366 days \n",year);
	
	}
	else
	{
		printf("not leap year  : %d -> 365 days \n",year);
	}
	return 0;

}
