#include<stdio.h>
#include<stdlib.h>

int main()
{

int size;

printf("enter size : ");
scanf("%d",&size);

int *ptr = (int *)malloc( sizeof(int) * size );

if(ptr == NULL )
{

 printf(" malloc() failed..memory not allocated..\n");
 return 0 ;
}

int i;

for(i = 0 ; i < size ; i++)
{

printf("enter %d value : ", i);

scanf(" %d", ( ptr+i) );

}

for( i = 0 ; i < size; i++)
{
 printf(" *(%lu + %d )= ( %lu ) = %d \n", ptr,i , (ptr+i), *(ptr + i ));
}

return 0 ;
}

