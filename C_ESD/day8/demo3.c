#include<stdio.h>
void accept_arr(int arr[], int size);
void print_arr(int arr[] , int size);
void rev_arr(int arr[] , int size);

int main()
{
	int arr[5];
	printf("size of arr : %lu \n", sizeof(arr));
	accept_arr(arr, 5);
	printf("before rev :\n");
	print_arr(arr , 5);
	rev_arr(arr , 5);
	printf("after rev \n");
	print_arr(arr , 5);

        return 0;
}

void rev_arr(int arr[], int size)
{
	int i = 0, j = size -1;
	while( i < j )
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;

		i++, j--;
	}

}

void accept_arr( int arr[] , int size  )
{

	printf("size of arr : %lu \n",sizeof(arr));

	int i;
	for(i = 0 ; i < size ; i++)
	{
		printf("Enter the index value : ",i);
		scanf("%d",&arr[i]);
	}
}

 void print_arr(int arr[] , int size)
{
	int i;
	for( i = 0 ; i < size ; i++ )
	{
		printf("arr[%d] = %d \n ", i,arr[i]);
	}
}



