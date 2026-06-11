#include<stdio.h>

int main()

{

int n1;
char ch;
float f1;
double d1;
printf(" enter int num : ");
scanf("%d", &n1);

printf("enter char :");
scanf("%*c%c",&ch);

printf("enter float :");
scanf("%f", &f1);

printf("enter double :");
scanf("%lf ", &d1);
printf("%d %c %f %lf  \n",n1,ch,f1,d1);

printf(" num char float double ");
scanf("%d %c %f %lf ", &n1, &ch, &f1, &d1);

printf("%d %c %f %lf \n", n1,ch,f1,d1);

return 0;

}
