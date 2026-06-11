#include<stdio.h>
#include<stdlib.h>

void accept_int_arr(int *ptr , int size )
{

int i;

for(i =0 ; i < size ; i++)

{

printf(" enter %d value : ", i );

scanf("%d", (ptr+i) );
}
}
void print_int_arr(int ptr[] , int size )
{
 int i;

for( i =0 ; i < size ; i++)
{
   printf(" *(%lu +  %d) = ( %lu ) = %d \n", ptr, i , (ptr + i), *(ptr +  i ));

}
}

int main()

{

int size;

printf(" enter size : ");
scanf("%d",&size) ;

int *ptr = (int *) malloc(sizeof(int) * size );

if( ptr ==  NULL )
{

printf( " malloc() failed..memory not alloacated..\n");

return 0;
}

accept_int_arr(ptr , size);

print_int_arr(ptr , size);

free(ptr);
ptr = NULL;
return 0 ;

}

