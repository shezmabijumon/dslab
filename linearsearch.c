#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char fn[10];
    char mn[10];
    char ln[10];
}name;
typedef struct{
    int empid;
    name Name;
    float sal;
}Employee;

Employee *ptr;
int n;
void linearsearch(){
	int j,key,d=0;
	printf("enter empid of employee to be searched: ");
	scanf("%d",&key);
	for(j=0;j<n;j++){
		if((ptr+j)->empid==key){
			printf("employee id: %d\n",(ptr+j)->empid);
			printf("name: %s %s %s\n",(ptr+j)->Name.fn,(ptr+j)->Name.mn,(ptr+j)->Name.ln);
			printf("salary: %.2f\n",(ptr+j)->sal);
			d++;
			break;
		}
	}
	if(d==0){
		printf("employee not found\n");
    }
}


void main(){
    int i;
    printf("enter number of employees:");
    scanf("%d",&n);
    ptr=(Employee *)malloc(n*sizeof(Employee));
    for(i=0;i<n;i++){
		printf("enter employee id: ");
		scanf("%d",&(ptr+i)->empid);
		printf("enter Name (first name, middle name and last name): ");
		scanf("%s%s%s",(ptr+i)->Name.fn,(ptr+i)->Name.mn,(ptr+i)->Name.ln);
		printf("enter salary: ");
		scanf("%f",&(ptr+i)->sal);
	}
	linearsearch();

}