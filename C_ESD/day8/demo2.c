#include<stdio.h>

/*
    Function Prototypes
    -------------------
    accept_arr()  : Accepts array elements from the user
    print_arr()   : Prints all elements of the array
    cal_sum_arr() : Calculates and returns sum of array elements
    find_max_arr(): Finds and returns maximum element from array
*/

void accept_arr( int arr[] , int size  );
void print_arr(int arr[] , int size);
int cal_sum_arr(int arr[] , int size);
int find_max_arr(int arr[], int size);

int main()
{
	int arr[5] ; // Array declaration (5 integers). Initially contains garbage values.

	accept_arr( arr , 5 ); // Accept elements from user
	print_arr(arr , 5);    // Print array elements

	// Calculate sum of array elements
	int sum = cal_sum_arr(arr , 5 );
	printf("sum of array element : %d \n",sum);

	// Find maximum element in array
	int max = find_max_arr(arr , 5 );
	printf("Max value : %d \n",max);

	return 0;
}
//---------------------------------------------------------------
/*
    Function : find_max_arr()

    Purpose :
    Find the maximum element from the array.

    Logic :
    1. Assume first element as maximum.
    2. Compare it with remaining elements.
    3. If a bigger element is found, update max.
    4. Finally return the maximum value.

    Example:
    Array = {10, 20, -50}

    Step 1: max = 10
    Step 2: 10 < 20  → max = 20
    Step 3: 20 < -50 → false
    Result: max = 20
*/

int find_max_arr(int arr[], int size)
{
	// int arr[3] = { 10 , 20 , - 50 };
	//                 0   1       2    3
	//                                  i
	//                     Max

	int i;
	int max = arr[0]; // assume first element is maximum

	for( i = 1 ; i< size ; i++)
	{
		//    10 <  20
		//    20 < -50
		if ( max < arr[i] ) // check if current element is greater
		{
		     // update max value
			max = arr[i];
		}
	}

	return max; // return maximum element
}

//---------------------------------------------------------------

/*
    Function : cal_sum_arr()

    Purpose :
    Calculate sum of all array elements.

    Example:
    arr = {10, 20, 30}

    Iteration process:
    sum = 0 + 10 = 10
    sum = 10 + 20 = 30
    sum = 30 + 30 = 60

    Final sum = 60
*/
int cal_sum_arr(int arr[] , int size)
{
	// arr[3] = { 10 , 20 , 30};
	//             0    1    2

	int sum=0 , i;

	for( i = 0 ; i < size ; i++)
	{
		sum = sum + arr[i]; // accumulate sum
	   //          0  +  10  => 10
	   //          10 +  20  => 30
	   //          30 +  30  => 60
	}

	return sum; // return calculated sum
}

//---------------------------------------------------------------

void accept_arr( int arr[] , int size  )
{
	int i;

	for(i = 0 ; i < size ; i++)
	{
		printf("Enter %dth index value : ",i);
		scanf("%d",&arr[i]); // store input value in array
	}
}

//---------------------------------------------------------------
void print_arr(int arr[] , int size)
{
	int i;

	for( i = 0 ; i < size ; i++ )
	{
		printf("arr[%d] = %d \n",i,arr[i]);
	}

}
//---------------------------------------------------------------
