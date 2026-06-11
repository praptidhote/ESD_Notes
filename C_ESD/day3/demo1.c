#include<stdio.h>

int main()
{
	int n1=0 , n2 =0, n3 = 0, res ;
	res + n1&& n2 ;
	printf(" %d && %d = %d \n",n1, n2, res);
	n1=0,n2=10;
	res = n1 && n2;
	printf("%d && %d = %d \n",n1,n2,res);
	n1=10, n2=0;
	res = n1 && n2;
	printf("%d && %d + %d \n",n1,n2,res);
	n1=-10,n2=10;
	res=n1 && n2 ;
	printf("%d && %d = %d \n", n1,n2,res);
	n1=0, n2=20;
	res = n1 && ++n2;
	printf("%d && %d = %d \n", n1,n2,res);
	n1=10, n2=0;
	res = n1 && ++n2;
	printf("%d && %d = %d \n", n1,n2,res);
	n1=10, n2=0;
	res = n1 && ++n2;
	printf("%d && %d = %d \n", n1,n2,res);
	n1 =10,n2=0;
	res = n1 && n2++;
	printf("%d && %d = %d \n",n1,n2,res);
	return 0;
}

