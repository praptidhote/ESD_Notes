#include<stdio.h>

int main()
{
 char str1[4] = { 'A', 'B', 'C', 'D'};
 char str2[4] = { 'a', 'b', 'c', 'd'};

int i;
for(i = 0; i<4;i++)
{
   printf("%c \n",str1[i]);
}
printf("\0 ");

printf("str1: %5 ; str2 :%5 \n", str1,str2);

return 0;

}
