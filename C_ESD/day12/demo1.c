#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book
{

	int id;
	char name[20];
	char author[20];
	float price;
	int year;

}book_t;

void print_books(book_t arr[], int N)
{

	printf("books : \n");
	for(int i = 0; i < N; i++)
	{
		printf("%d %s %s %f %d\n", arr[i].id, arr[i].name, arr[i].author, arr[i].price,arr[i].year);
	}

}

void print_books_author(book_t arr[],int N, char *author)
{
	printf("books of %s : \n",author);
	for(int i =0 ; i < N ; i++)
	{
		if(!strcmp(author, arr[i].author))
			printf("%d %s %s %f %d \n", arr[i].id, arr[i].name, arr[i].author, arr[i].price, arr[i].year);
	}
}

void print_book_year(book_t arr[], int N, int year )
{
	printf("books of %d : \n", year);
	for(int i = 0; i < N; i++)
	{

		if(year == arr[i].year)
			printf("%d %s %s %f %d \n" , arr[i].id, arr[i].name, arr[i].author, arr[i].price, arr[i].year);
	}
}
float find_avg_price(book_t arr[], int N)
{

	float sum = 0;
	for(int i = 0; i < N ; i++)
	{
		
		sum += arr[i].price;
		printf("sum : %f\n",sum);
	}

	return sum / N;
}

int main(void)
{

	int choice;
	int N;
	int count = 0;
	int id;

	printf("enter number of books : ");
	scanf("%d",&N);

	book_t *arr = (book_t*)malloc(sizeof(book_t) * N);

	do{

		printf("0.exit\n");
		printf("1.add book\n");
		printf("2.delete books\n");
		printf("3.print books\n");
		printf("4.print books of author\n");
		printf("5.print books of year\n");
		printf("6.average price\n");

		printf("enter your choice : ");
		scanf("%d", &choice);

		switch(choice)
		{

			case 1:

				printf("enter book (id, name, author, price, year: ");
				scanf("%d %s %s %f %d", &arr[count].id, arr[count].name, arr[count].author, &arr[count].price, &arr[count].year);
				count++;
				break;


			case 2:

				printf("enter id : ");
				scanf("%d", &id);
				for(int i = 0; i < count ; i++)
				{
					if(id == arr[i].id)
					{

						for(int j = i + 1 ; j < count ; j++ )
							arr[ j - 1 ] =arr[j];
						count--;
						break;
					}
				}
				break;

			case 3:

				print_books(arr,count);
				break;


			case 4:

				print_books_author(arr, count, "Prapti");
				break;


			case 5:

				print_book_year(arr, count, 2026);
				break;


                         case 6:

				printf(" avg price = %f\n" , find_avg_price(arr, count));
				break;

		}

	}while(choice != 0);

	FILE *fp = fopen("book.db", "wb");
	fwrite(arr, sizeof(book_t), count, fp);
	fclose(fp);

	free(arr);

	return 0;

}



