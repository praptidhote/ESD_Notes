//1. Student Record Management System
//Problem Statement Write a C program to manage student records.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    int id;
    char name[50];
    char dept[30];
    float marks;
    int year;
};

int count=0;

void addStudent(struct Student *s){
    printf("Enter ID: ");
    scanf("%d",&s[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]",s[count].name);

    printf("Enter Department: ");
    scanf(" %[^\n]",s[count].dept);

    printf("Enter Marks: ");
    scanf("%f",&s[count].marks);

    printf("Enter Year: ");
    scanf("%d",&s[count].year);

    count++;
}

void printStudents(struct Student *s){
    for(int i=0;i<count;i++){
        printf("\nID:%d Name:%s Dept:%s Marks:%.2f Year:%d",
        s[i].id,s[i].name,s[i].dept,s[i].marks,s[i].year);
    }
}

void avgMarks(struct Student *s){
    float sum=0;
    for(int i=0;i<count;i++)
        sum+=s[i].marks;

    printf("\nAverage Marks=%.2f",sum/count);
}

int main(){

    int n,choice;
    printf("Enter number of students: ");
    scanf("%d",&n);

    struct Student *s=malloc(n*sizeof(struct Student));

    do{
        printf("\n1.Add\n2.Print\n3.Average\n4.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: addStudent(s); break;
            case 2: printStudents(s); break;
            case 3: avgMarks(s); break;
        }
    }while(choice!=4);

    FILE *fp=fopen("students.db","wb");
    fwrite(s,sizeof(struct Student),count,fp);
    fclose(fp);

    free(s);
}
