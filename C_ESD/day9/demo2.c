#include<stdio.h>

/*
	strstr()
	Purpose:
	----------
	strstr() is used to find the FIRST occurrence of a substring inside a string.	
	If the substring is found:
		→ It returns the address (pointer) of the first character of that substring inside the string.
	If the substring is NOT found:
		→ It returns NULL.	
	Prototype:
	----------
	char *strstr(const char *str, const char *sub);
	Parameters:	
		str : Pointer to the null-terminated string to be searched.
		sub : Pointer to the null-terminated substring to be searched inside the string.
	Return Value:
		If substring is found → pointer to first occurrence
		If substring not found → NULL
*/

char *my_strstr(const char *str, const char *sub)
{
	int len1 = strlen(sub);
	for(int i = 0; str[i] != '\0'; i++)
	{
		if(strncmp(&str[i], sub, len1) == 0)
		{
			return &str[i];
		}
	}
	return NULL;
}

int main()
{

	char str1[] = "Sunbeam";  // main string
	char sub[] = "bea";       // substring to search

	printf("str1 : %s \n",str1);

	// strstr() searches for substring "bea" inside "Sunbeam"
	char *ptr = strstr(str1 , sub );

	//char *ptr = my_strstr(str1 , sub );

	if( ptr == NULL)
	{
		// If substring not found
		printf("String is not found : %s \n",sub);
	}
	else
	{
		// If substring found, ptr stores address of first occurrence
		printf("Sub string is present : %lu location \n",ptr);
	}


/*
	// Example of strncmp()

	char str2[] = "ABCDEF"; // first string
	char str3[] = "ABC";    // second string

	// strncmp() compares first 'n' characters of two strings
	// Prototype:
	// int strncmp(const char *str1 , const char *str2 , size_t n);

	int cmp = strncmp(str2,str3, 3 );

	
		// Return value of strncmp()

		// 0   → first n characters are equal
		// >0  → first string is greater
		// <0  → second string is greater
	

	if(cmp == 0 )
		printf("both string same");
	else
		printf("Not same");
*/

	return 0;
}

