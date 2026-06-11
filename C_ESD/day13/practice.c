#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct date
{
 int dd;
 int mm;
 int yy;

};
typedef struct employee
{
  int id;
  char name[20];
  char dept[20];
  float salary;
  struct date dob;
}emp_t;

void accept_emp(emp_t *e1);
void add_employee_file(emp_t *e1);
void print_emp(emp_t e1);
void display_employee_file(void);
void search_emp_by_id(int id);
void search_emp_by_name(char *str);
void update_emp_by_id(int id);
void delete_emp_by_id(int id);

int main()
{
   int ch;
   emp_t e1;
   int id;

  do
  {  
	printf(" Welcome to employee management system..\n");
	printf("0.Exit\n1.add Employee\n2.Display Employee\n3.search by id\n4.search by name\n5.update by id\n6.delete by id\n7.total employee\n");
	printf(" your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 0:printf("exit\n");
			break;

		case 1:printf("----------------------------------------------------\n");
		       accept_emp(&e1);
		       add_employee_file(&e1);
			printf("-----------------------------------------------------\n");
			break;

		case 2:printf("------------------------------------------------------\n");
		       printf("all employee info :\n");
			printf("-----------------------------------------------------\n");
			display_employee_file();
			printf("-----------------------------------------------------\n");
			break;

		case 3:printf("------------------------------------------------------\n");
			printf("search by id\n");
			printf("enter the id to search : ");
			scanf("%d",&id);
			search_emp_by_name(id);
			printf("------------------------------------------------------\n");
			break;

		case 4:printf("------------------------------------------------------\n");
			char str[20];
			printf("enter the name to search : ");
			scanf("%*c%s",str);
			search_emp_by_name(str);
			printf("------------------------------------------------------\n");
			break;

		case 5:printf("-------------------------------------------------------\n");
			printf("update emp by id\n");
			printf("enter the id to update : ");
			scanf("%d",&id);
			update_emp_by_id(id);
			printf("-------------------------------------------------------\n");
			break;

		case 6:printf("---------------------------------------------------------\n");
			printf("delete emp by id\n");
			printf("enter the id to delete : ");
			scanf("%d",&id);
			delete_emp_by_id(id);
			printf("--------------------------------------------------------\n");
			break;
		default:
			break;
	}	
  }while (ch != 0);
   return 0;
}

void accept_emp(emp_t *e1)
{
  printf("enter id of employee : ");
  scanf("%d",&e1->id);
  printf("enter the name of empoyee : ");
  scanf("%*c%s",&e1->name);
  printf("enter the dept of empoyee : ");
  scanf("%*c%s",&e1->dept);
  printf("enter the salary of empoyee (DD MM YY ): ");
  scanf("%d%d%d",&e1->dob.dd,&e1->dob.mm,&e1->dob.yy);
}

void add_employee_file(emp_t *e1)
{

FILE *fp = fopen("emp.db","ab");
if(fp == NULL)
	printf("Unable to open file\n");
	return;
}

int ret = fwrite(e1,sizeof(emp_t),1,fp);
if(ret == 0){
	printf("error while writing to file\n");
}else {
	printf("employee added successfully\n");
}
fclose(fp);
}
}
void display_employee_file(void)
{
	emp_t e1;
	FILE *fp = fopen("emp.db","rb");
	 
	while((fread(&e1,sizeof(e1),1,fp))!= 0)
  {
     if(e1.id == id)
      {
		printf("employee found : \n");
		print_emp(e1);
		return;
       }
   }
   printf("sorry employee not found : \n");
   fclose(fp);
}

void search_emp_by_name(char *str)
{
   emp_t e1;
   FILE *fp = fopen("emp.db","eb");
   
   while((fread(&e1,sizeof(e1),1,fp)) != 0)
   {
     if(strcmp(e1.name,str) == 0)
       {
            printf("Employee Found by name: \n");
            print_emp(e1);
            return;
       }
    }
    printf("Sorry Employee Not Found : \n");
    fclose(fp);
}

void update_emp_by_id(int id)
{
    emp_t e1;
    FILE *fp = fopen("emp.db","rb+");
    
    while( (fread(&e1,sizeof(e1),1,fp)) != 0 )
    {
       if(e1.id == id)
       {
            printf("Employee Found : \n");
            print_emp(e1);
            float sal;
            printf("Enter new sal : ");
            scanf("%f",&sal);
            e1.salary = sal;
            fseek(fp, -1 * sizeof(e1), SEEK_CUR);
            fwrite(&e1,sizeof(e1),1,fp);
            printf("Employee Updated Sucsessfully... \n");
            fclose(fp);
            return;
       }
    }
    printf("Sorry Employee Not Found : \n");
    fclose(fp);
}
void delete_emp_by_id(int id)
{
     emp_t e1;
     FILE *fp = fopen("emp.db","rb+");
    
     while( (fread(&e1,sizeof(e1),1,fp)) != 0 )
     {
        if(e1.id == id)
        {
             while(fread(&e1, sizeof(e1), 1, fp) != 0)
                {
                    fseek(fp, -2 * sizeof(e1), SEEK_CUR);
                    fwrite(&e1, sizeof(e1), 1, fp);
                    fseek(fp, +1 * sizeof(e1), SEEK_CUR);
                }
                break;
        }
     }
    fseek(fp, -1 * sizeof(e1), SEEK_END);
	int pos = ftell(fp);
	printf("%d\n", pos);
	fclose(fp);
	truncate("books.txt", pos);

 }
