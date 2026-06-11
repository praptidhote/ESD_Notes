//3. Product Inventory System
//Problem Statement Write a C program for product inventory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
    int id;
    char name[50];
    char company[40];
    float price;
    int qty;
};

int count=0;

void addProduct(struct Product *p){
    printf("Enter ID: ");
    scanf("%d",&p[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]",p[count].name);

    printf("Enter Company: ");
    scanf(" %[^\n]",p[count].company);

    printf("Enter Price: ");
    scanf("%f",&p[count].price);

    printf("Enter Quantity: ");
    scanf("%d",&p[count].qty);

    count++;
}

void printProducts(struct Product *p){
    for(int i=0;i<count;i++){
        printf("\nID:%d Name:%s Company:%s Price:%.2f Qty:%d",
        p[i].id,p[i].name,p[i].company,p[i].price,p[i].qty);
    }
}

void totalValue(struct Product *p){
    float total=0;

    for(int i=0;i<count;i++)
        total+=p[i].price*p[i].qty;

    printf("\nTotal Inventory Value=%.2f",total);
}

int main(){

    int n,choice;

    printf("Enter number of products: ");
    scanf("%d",&n);

    struct Product *p=malloc(n*sizeof(struct Product));

    do{
        printf("\n1.Add\n2.Print\n3.Total Value\n4.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: addProduct(p); break;
            case 2: printProducts(p); break;
            case 3: totalValue(p); break;
        }

    }while(choice!=4);

    FILE *fp=fopen("products.db","wb");
    fwrite(p,sizeof(struct Product),count,fp);
    fclose(fp);

    free(p);
}
