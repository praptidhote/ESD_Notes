#include<stdio.h>
#include<stdlib.h>

int main()
{

int size;
printf(" enter size : ");
scanf("%d",&size);

int *ptr = ( int *)malloc( sizeof(int) * size );

if(ptr == NULL)
{

printf("malloc() failed..memory not allocated..\n");
return 0;
}


int i;

for(i = 0 ; i < size ;i++)
{
 printf("ptr[%d] = %d \n" ,i , ptr[i] );

}

free(ptr);
ptr = NULL;

return 0;
}

