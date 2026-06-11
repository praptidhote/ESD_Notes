#include<stdio.h>

int main()
{

	int admin = 123456;
	int passkey;

	do
	{

		printf("enter the password : ");
		scanf("%d",&passkey);

		if(passkey == admin)
		{
			printf("login sucessfully...\n");
		}
		else
		{
			printf("try again..\n");
		}

	}while(passkey != admin);

	return 0;
}

