#include<stdio.h>

// Acsii values of escape sequence

int main()
{
	//  \n => 10
	printf("  \\n => %d  \n",'\n'); //Acsii value of \n is 10
	printf("  \\b => %d  \n",'\b'); //Acsii value of \b is 8
	printf("  \\r => %d  \n",'\r'); //Acsii value of \r is 13
	printf("  \\t => %d  \n",'\t'); //Acsii value of \t is 9
	printf("  \\a => %d  \n",'\a'); //Acsii value of \a is 7

	return 0;
}
