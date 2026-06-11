#include<stdio.h>
#include<stdlib.h>

int main()

{

int size;

printf("enter the size : ");
scanf("%d",&size);

char *cptr = (char*) calloc(sizeof(char) , size);

if(cptr == NULL )
{

printf("calloc gets failed..\n");
return 0;
}

int i;

for(i = 0; i < size ; i++)
{

printf("%d", cptr[i]);
}
printf("\n");

printf("enter the string : ");

scanf("%c%s", cptr);

printf("cptr : %s",cptr);

free(cptr);
cptr = NULL;

return 0;
}

