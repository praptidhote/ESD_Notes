#include<stdio.h>
 
int main()
{
	int res , a =10, b =0 , c = -10;
	res = (10 ,20 ,30);
	printf(" res = %d \n ", res );
	res = (a,b,c);
	printf (" res = %d \n ", res);
	res = ( a++, b++, --c);
	printf (" a = %d , b=%d , c=%d , res = %d \n ",a,b,c,res);
	a = 10;
	res = ( a++, a++, a++);
	printf(" res = %d , a = %d \n ", res, a);

	return 0 ;
}

