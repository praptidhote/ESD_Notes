#include<stdio.h>

int main()
{
int month;
printf(" enter the month : ");
scanf("%d", &month);

if (month == 1 )
	printf(" jan has 31 days\n");
else if(month == 2 )
	printf(" feb has 28/29 days\n");
else if(month == 3)
	printf(" march has 30 days\n");
else if(month == 4)
	printf(" april has 31 days\n");
else if(month == 5)
	printf("may has 30 days \n");
else if(month == 6 )
	printf("jun has 31 days \n");
else if(month == 7)
	printf("julay has 30 days \n" );
else if(month == 8)
	printf(" aug has 31 days \n");
else if(month == 9)
	printf(" sep has 30 days \n");
else if(month == 10 )
	printf(" oct has 31 days \n");
else if(month == 11 )
	printf("nov has 30 days \n ");
else if(month == 12)
	printf("des has 31 days \n");
else
	printf("invalid month \n");

return 0;
}
