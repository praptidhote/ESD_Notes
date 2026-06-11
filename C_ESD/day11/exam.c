#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int id;
    char name[20];
    char author[20];
    float price;
    int year;
}book;

void print_books(book arr[], int n)
{
    for(int i=0;i<n;i++)
        printf("%d %s %s %.2f %d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
}

float avg_price(book arr[], int n)
{
    float sum=0;
    for(int i=0;i<n;i++)
        sum+=arr[i].price;

    if(n==0) return 0;
    return sum/n;
}

int main()
{
    int N,choice,count=0,id;
    char author[20];
    int year;

    printf("Enter number of books: ");
    scanf("%d",&N);

    book *arr=(book*)calloc(N,sizeof(book));

    do
    {
        printf("\n0.Exit\n1.Add\n2.Delete\n3.Print\n4.Author\n5.Year\n6.Avg price\n");
        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(count==N)
                {
                    printf("Storage full\n");
                    break;
                }
                printf("Enter id name author price year: ");
                scanf("%d %s %s %f %d",&arr[count].id,arr[count].name,arr[count].author,&arr[count].price,&arr[count].year);
                count++;
                break;

            case 2:
                printf("Enter id: ");
                scanf("%d",&id);
                for(int i=0;i<count;i++)
                {
                    if(arr[i].id==id)
                    {
                        for(int j=i;j<count-1;j++)
                            arr[j]=arr[j+1];
                        count--;
                        break;
                    }
                }
                break;

            case 3:
                print_books(arr,count);
                break;

            case 4:
                printf("Enter author: ");
                scanf("%s",author);
                for(int i=0;i<count;i++)
                    if(strcmp(arr[i].author,author)==0)
                        printf("%d %s %s %.2f %d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
                break;

            case 5:
                printf("Enter year: ");
                scanf("%d",&year);
                for(int i=0;i<count;i++)
                    if(arr[i].year==year)
                        printf("%d %s %s %.2f %d\n",arr[i].id,arr[i].name,arr[i].author,arr[i].price,arr[i].year);
                break;

            case 6:
                printf("Average price = %.2f\n",avg_price(arr,count));
                break;
        }

    }while(choice!=0);

    free(arr);
    return 0;
}
