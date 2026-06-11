#include<stdio.h>

int main()

{

int n1 = 10 , n2 = 20, sum;
sum = n1 + n2;

n2 += n1 + 20 + 20;
n2 = n2 + n1 +20 +20;

int n3 = 30;
n3 -= 20;

int n4 = 40;
n4 *= 2 ;

int n5 =10 ;
n5 /= 2;

int n6 = 20;
n6 %= 3;
printf("n6 = %d \n" ,n6);
return 0 ;


}
