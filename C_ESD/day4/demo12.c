#include<stdio.h>
#include<math.h>

int main()

{

	int num, cnt = 0, temp;
	printf("enter num : ");
	scanf("%d",&num );

	temp = num;
	int rem;

	do
	{
		rem = num % 10;
		cnt++;
		num = num / 10;

	}while(num > 0);

	printf("cnt %d : %d \n",temp,cnt);
	num = temp;
	int arm = 0;

	do
	{
		rem = num % 10;
		arm = arm + pow(rem ,cnt);
		num = num / 10;

	}while(num > 0);

	if(temp == arm )
	{
		printf("armstrong..\n");
	}
	else
	{
		printf("not armstrong..\n");
	}
	return 0;

}

