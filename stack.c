#include<stdio.h>

int stack[10];
int n,top=-1;

void push(int x){
    if(top==n){
        printf("stack is full");
        return;
    }
    top=top+1;
    stack[top]=x;
}
void pop(){
    if (top==-1){
        printf("stack is empty");
        return;
    }
    printf("deleted element is %d",stack[top]);
    top=top-1;
}
void display(){
    if (top==-1){
        printf("stack is empty");
        return;
    }
    for(int i=0;i<=top;i++){
        printf("%d  ",stack[i]);
    }
    printf("\n");
}
void main(){
    int ch,x;
    printf("enter size of stack:");
    scanf("%d",&n);
    do{
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter element:");
            scanf("%d",&x);
            push(x);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("exiting..");
            break;
            default:
            printf("invalid choice\n");
            break;
        }
    }while (ch!=4);
}