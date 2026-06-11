#include<stdio.h>

int main()
{
	int n1,n2,n3;
	printf("enter 3 value : ");
	scanf("%d%d%d",&n1,&n2,&n3);
	
	if(n1 > n2)
	{
		if(n1 > n3)
			printf("%d : n1 is grater \n",n1);
		else
		{
			printf("%d : n3 is grater\n",n3);
		
		}
	
	
	}
	else
	{

		if(n2 > n3)
			printf("%d : n2 is grater\n",n2);
		else
		{
			printr("%d : n3 is grater\n",n3);

		}
	}return 0;
}
