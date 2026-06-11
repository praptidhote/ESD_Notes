#include<stdio.h>

// Format specifier width

int main()
{
	//Right align
 	printf("Num1= %5d \n",10); // here 10 will be right align and 5 is the width of format specifier which means total 5 character space will be reserved for num1 and 10 will be printed in that space and remaining space will be filled with blank space
	//            _____
	//      Num1=    10

	printf("N1=%6d---N2=%6d \n",10,20);
	//      N1=____10---N2=____20

	//Left align
	printf("--N3=%-6d--\n",50);// here 50 will be left align and 6 is the width of format specifier which means total 6 character space will be reserved for N3 and 50 will be printed in that space and remaining space will be filled with blank space
        //      --N3=50___

	printf("val=%2d \n",123456);// here 123456 will be printed as it is because width of format specifier is less than number of digits in 123456






	return 0;

}
