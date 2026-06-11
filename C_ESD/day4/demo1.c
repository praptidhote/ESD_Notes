#include<stdio.h>

int main()
{
	int month;

	printf("enter the month : ");
 	scanf("%d",&month);

	switch ( month )
	{
		case 1 :
			printf("jan has 31 days\n");
			break;

		case 2 :
			printf("fen has 28/29 days\n");
			break;

		case 3 :
			printf("march has 31 days\n");
			break;

		case 4 :
			printf("april has 30 days\n");
			break;

		case 5 :
			printf("may has 31 days\n");
			break;

		case 6 :
			printf("jun has 30 days\n");
			break;

		case 7 :
			printf("juley has 31 days\n");
			break;

		case 8 :
			printf("aug has 30 days\n");
			break;

		case 9 :
			printf("sep has 31 days\n");
			break;

		case 10 :
			printf("oct has 30 days\n");
			break;

		case 11 :
			printf("nov has 31 days\n");
                        break;

		case 12 :
			printf("des has 30 days\n");
			break;

		default :

			printf("invalid month \n");
			break;
        
	}
        return 0;

}

	
