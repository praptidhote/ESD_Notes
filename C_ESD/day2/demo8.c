#include<stdio.h>

extern int a;

int a = 50;

int main()
{

int num1;

int num2;

int num3;

num1= 100;
num2= 200;

printf("num1 = %d\n", num1);
printf("num2 = %d\n", num2);
printf("num3 = %d\n", num3);
printf("a ( global) = %d\n", a);

return 0;

}

