#include<stdio.h>
#include<string.h>


int main()
{

  char str1[] = "india";
  char ch = 'i';
 // char ch = 'p';
  char *ptr = strchr(str1, ch);
  printf("str1 : %s \n",str1);
  printf("str1 : %lu \n",str1);
  printf("ptr : %lu \n",ptr);
  return 0;
}
char * my_strchr(const char *str,int c)
{
  for(int i=0; str[i] != '\0'; i++)
  {
         if(str[i]== c )
	  {
		return (char *)(str + i);
	   }
   }
return NULL;
}

