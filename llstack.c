#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *top=0,*newnode,*temp;
void push();
void pop();
void display();
void main(){
    printf("\nMENU\n\n");
    printf("1.Push\n2.Pop \n3.Display\n4.Exit\n");
    int choice;
    do{
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        push();
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        printf("Exiting from the program\n");
        break;
        default:
        printf("Enter a valid choice\n");
        break;
        }
    }while(choice!=4);
}
void push(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->link=top;
    printf("Enter the value to insert: ");
    scanf("%d",&newnode->data);
    top=newnode;
}
void pop(){
    if(top==0){
        printf("The stack is empty\n");
    }
    else{
        temp=top;
        top=top->link;
        free(temp);
    }
}
void display(){
    if(top==0){
        printf("The stack is empty\n");
    }
    else{
        temp=top;
        printf("The stack is:\n");
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->link;
            printf("\n");
        }
    }
}
