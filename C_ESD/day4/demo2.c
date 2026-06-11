#include<stdio.h>

int main()
{
	int num1, num2;
	char opr;
	float res;

	printf("enter the num1 : ");
	scanf("%d",&num1);

	printf("enter thr opr + - * / %% : ");
	scanf("%*c%c",&opr);

	printf("enter the num2 : ");
	scanf("%d",&num2);

	switch (opr)
	{
		case '+' :
			res = num1 + num2;
			break;

		case '-' :
			res = num1 - num2;
			break;

		case '*' :
			res = num1 * num2;
			break;

		case '/' :
			if (num2 ==0 )
				printf("can't div by zero..\n");
			else
		        	res = num1 / num2;
			break;

		default :
			printf("invalid oprator \n");
	}
	if((num2 !=0 && opr == '/' )||( opr != '/' ))
	{
		printf(" %d %c %d = %.2f \n",num1,opr,num2,res);
	}
	
	return 0;

}
