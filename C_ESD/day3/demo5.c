#include<stdio.h>

int main()
{

int res, n1=10, n2=0,n3=-5;
res = n1 && n2 && n3;

res = ++n1 && ++n2 || n3-- ;
printf("res: %d n1:%d n2 : %d n3 : %d \n",res,n1,n2,n3);

res = n1 && n2 || n3; 
printf("res: %d n1: %d n2 : %d n3 : %d \n",res,n1,n2,n3);

n1 = 10, n2 = 0, n3 = -6;
res = n1 || n2 && n3 ;

printf("res: %d n1: %d n2 : %d n3 : %d \n",res,n1,n2,n3);
n1= 0, n2=5, n3=10;

printf("res: %d n1: %d n2 : %d n3 : %d \n",res,n1,n2,n3);

return 0;

}

