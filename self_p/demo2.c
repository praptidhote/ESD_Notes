// 2. Employee Management System
// Problem Statement Write a C program to manage employee records.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{
    int id;
    char name[50];
    char dept[30];
    float salary;
};

int count=0;

void addEmployee(struct Employee *e){
    printf("Enter ID: ");
    scanf("%d",&e[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]",e[count].name);

    printf("Enter Department: ");
    scanf(" %[^\n]",e[count].dept);

    printf("Enter Salary: ");
    scanf("%f",&e[count].salary);

    count++;
}

void printEmployees(struct Employee *e){
    for(int i=0;i<count;i++){
        printf("\nID:%d Name:%s Dept:%s Salary:%.2f",
        e[i].id,e[i].name,e[i].dept,e[i].salary);
    }
}

void avgSalary(struct Employee *e){
    float sum=0;

    for(int i=0;i<count;i++)
        sum+=e[i].salary;

    printf("\nAverage Salary = %.2f",sum/count);
}

int main(){

    int n,choice;

    printf("Enter number of employees: ");
    scanf("%d",&n);

    struct Employee *emp=malloc(n*sizeof(struct Employee));

    do{
        printf("\n1.Add\n2.Print\n3.Average Salary\n4.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: addEmployee(emp); break;
            case 2: printEmployees(emp); break;
            case 3: avgSalary(emp); break;
        }

    }while(choice!=4);

    FILE *fp=fopen("employees.db","wb");
    fwrite(emp,sizeof(struct Employee),count,fp);
    fclose(fp);

    free(emp);
}
