#include<stdio.h>

int main()
{

int n1 = 10;
float pi = 4.14, res;
double d1 = 20.3;
res= n1 + pi;

printf("res = %d \n",res);

printf("n1 = %d \n",n1);
res = 'A' + pi;

printf("res = %.2f \n",res);
res = n1 + d1;

printf("res = %.2f \n", res);
char ch = 'A', res1;

unsigned char ch1 = 10, res2;

res1 = ch > ch1;
printf("res = %d \n", res1);

return 0;

}
