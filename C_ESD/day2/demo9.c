#include<stdio.h>

int main()
{

int num1;
float f1;
double d1;
char ch;

printf("size of int : %d \n",sizeof(int));
printf("size of float : %d \n",sizeof(float));
printf("size of double : %d \n",sizeof(double));
printf("size of char : %d \n", sizeof(char));

printf("size of num1 : %d \n",sizeof(num1));
printf("size of f1 : %d \n", sizeof(f1));
printf("size of d1 : %d \n", sizeof(d1));
printf("size of ch : %d \n",sizeof(d1));

printf("size of num1 : %d \n",sizeof(10));
printf("size of f1 : %d \n",sizeof(3.14f));
printf("size of d1: %d \n", sizeof(10.2));
printf(" size of ch : %d \n", sizeof('A'));

return 0;

}
