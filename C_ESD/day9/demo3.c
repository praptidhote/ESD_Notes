#include<stdio.h>
#include<string.h>

int main()
{
    char str1[] = "DAC,DMC,DESD,DITISS,DBDA";
    char delim = ',';

    char *ptr = strtok(str1, &delim);
 
    printf("ptr : %s \n", ptr);
    ptr = strtok(NULL, &delim);

    printf("ptr : %s \n", ptr);
    ptr = strtok(NULL, &delim);

    printf("ptr : %s \n", ptr);
    ptr = strtok(NULL, &delim);

    printf("ptr : %s \n", ptr);
    ptr = strtok(NULL, &delim);

    printf("ptr : %s \n", ptr);
    ptr = strtok(NULL, &delim);

    printf("ptr : %s \n", ptr);
    printf("str1 : %s \n", str1);
    return 0;
}

