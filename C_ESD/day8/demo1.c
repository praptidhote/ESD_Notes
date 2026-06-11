#include<stdio.h>

int main()
{
	int arr[5] ; // Array declaration: array of 5 integers (initially contains garbage values)

	//int arr[ ]; // Error → size must be specified if array is not initialized

	//int arr[ ] = {10 , 20 , 30 , 40 , 50 }; // OK → compiler automatically counts number of elements

	//int arr[5] = { 10 , 20 }; // OK → remaining elements automatically initialized to 0

	//printf("size of arr : %lu \n", sizeof( arr ));  // would print total size of array in bytes (5 * 4 = 20)

	// size of array = number of elements * size of data type
	//                      5           *        4
	//                     = 20 bytes (on most systems)

	int i;

	// accept array elements from user
	for(i = 0 ; i < 5 ; i++)
	{
		printf("Enter the value : ",i); // prompt user for each index
		scanf("%d",&arr[i]); // store entered value in array
	}

	// print array elements
	for( i = 0 ; i < 5 ; i++ )
	{
		printf("arr[%d] = %d \n",i,arr[i]); // display index and corresponding value
	}

	return 0;

}
