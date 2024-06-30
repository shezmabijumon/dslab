
#include<stdio.h>

char expr[50],item;
char *e;
char stack[50];
int top=-1;

int priority(char op);
void push(char item);
char pop();

void main(){
	int n1,n2,n3,num;
	int ch;
	do{
		printf("\n1.infix to postfix\n2.evaluation of postfix\n3.exit\n\n");
		printf("enter choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("enter the infix expression: ");
			scanf("%s",expr);
			e=expr;			
			printf("the postfix expression is:\n");
			while(*e!='\0'){
				if(*e=='+' || *e=='-' || *e=='*' || *e=='/' || *e=='%'){
					while(priority(stack[top])>=priority(*e)){
						printf("%c",pop());
					}
					push(*e);
				}
				else if(*e=='(')
					push('(');
				else if(*e==')'){
					item=pop();
					while(item!='('){
						printf("%c",item);	
						item=pop();
					}
				}
				else
					printf("%c",*e);
				e++;
			}
			while(top!=-1)
				printf("%c",pop());
			printf("\n");
			break;

			case 2:
			printf("enter the postfix expression: ");
			scanf("%s",expr);
			e=expr;
			while(*e!='\0'){
				if(*e=='+' || *e=='-' || *e=='*' || *e=='/' || *e=='%'){
					n1=pop();
					n2=pop();
					
					switch(*e){
						case '+':
						n3=n2+n1;
						push(n3);
						break;

						case '-':
						n3=n2-n1;
						push(n3);
						break;

						case '*':
						n3=n2*n1;
						push(n3);
						break;

						case '/':
						n3=n2/n1;
						push(n3);
						break;

						case '%':
						n3=n2%n1;
						push(n3);
						break;				
					}
				}
				else{
					num=*e-48;
					push(num);				
				}
				e++;
			}
			item=stack[top];
			printf("the resultant is %d\n",item);
			break;

			case 3:
			printf("exiting..\n");
			break;
			default:
			printf("invalid choice\n");
		}
	}while(ch!=3);
}

int priority(char op){
	if(op=='*' || op=='/' || op=='%')
		return 2;
	if(op=='+' || op=='-')
		return 1;
	if(op=='(')
		return 0;
	return 0;
}

void push(char item){
	top=top+1;
	stack[top]=item;
}

char pop(){
	item=stack[top];
	top=top-1;
	return item;
}
