#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book{
    int id;
    char name[20];
    char author[20];
    float price;
    int year;
}book_t;

void print_books(book_t arr[], int N)
{
    printf("Books : \n");
    for(int i = 0; i < N; i++)
        printf("%d %s %s %f %d\n",
        arr[i].id, arr[i].name, arr[i].author, arr[i].price, arr[i].year);
}

void print_books_author(book_t arr[], int N, char *author)
{
    printf("Books of %s : \n", author);
    for(int i = 0; i < N; i++)
        if(!strcmp(author, arr[i].author))
            printf("%d %s %s %f %d\n",
            arr[i].id, arr[i].name, arr[i].author, arr[i].price, arr[i].year);
}

void print_books_year(book_t arr[], int N, int year)
{
    printf("Books of %d : \n", year);
    for(int i = 0; i < N; i++)
        if(year == arr[i].year)
            printf("%d %s %s %f %d\n",
            arr[i].id, arr[i].name, arr[i].author, arr[i].price, arr[i].year);
}

float find_avg_price(book_t arr[], int N)
{
    if(N == 0)
        return 0;

    float sum = 0;
    for(int i = 0; i < N; i++)
        sum += arr[i].price;

    return sum / N;
}

int main(void)
{
    int choice;
    int N;
    int count = 0;
    int id;

    printf("Enter number of books : ");
    scanf("%d", &N);

    book_t *arr = (book_t*)malloc(sizeof(book_t) * N);

    do{
        printf("\n0. Exit\n");
        printf("1. Add book\n");
        printf("2. Delete book\n");
        printf("3. Print books\n");
        printf("4. Print books of author\n");
        printf("5. Print books of year\n");
        printf("6. Average price\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter book (id name author price year): ");
                scanf("%d %s %s %f %d",
                      &arr[count].id,
                      arr[count].name,
                      arr[count].author,
                      &arr[count].price,
                      &arr[count].year);
                count++;
                break;

            case 2:
                printf("Enter id : ");
                scanf("%d", &id);

                for(int i = 0; i < count; i++)
                {
                    if(id == arr[i].id)
                    {
                        for(int j = i+1; j < count; j++)
                            arr[j-1] = arr[j];
                        count--;
                        break;
                    }
                }
                break;

            case 3:
                print_books(arr, count);
                break;

            case 4:
            {
                char author[20];
                printf("Enter author : ");
                scanf("%s", author);
                print_books_author(arr, count, author);
                break;
            }

            case 5:
            {
                int year;
                printf("Enter year : ");
                scanf("%d", &year);
                print_books_year(arr, count, year);
                break;
            }

            case 6:
                printf("Avg price = %f\n", find_avg_price(arr, count));
                break;
        }

    }while(choice != 0);

    FILE *fp = fopen("book.db", "wb");
    fwrite(arr, sizeof(book_t), count, fp);
    fclose(fp);

    free(arr);

    return 0;
}
