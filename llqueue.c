#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct node *front=0,*rear=0,*newnode,*temp;
void insert();
void delete();
void display();
void main(){
    int choice;
    printf("-----MENU-----\n\n");
    printf("1.Insert \n2.Delete \n3.Display \n4.Exit\n");
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delete();
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
void insert(){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->link=0;
    printf("Enter the value to insert: ");
    scanf("%d",&newnode->data);
    if(front==0 && rear==0){
        front=newnode;
        rear=newnode;
    }else{
        rear->link=newnode;
        rear=newnode;
    }
}
void delete(){
    if(front==0 && rear==0){
        printf("The queue is empty\n");
    }
    else if(front==rear){
        temp=front;
        front=0;
        rear=0;
        free(temp);
    }
    else{
        temp=front;
        front=front->link;
        free(temp);
    }
}
void display(){
    if(front==0 && rear==0){
        printf("The queue is empty\n");
    }
    else{
        printf("The queue is:");
        temp=front;
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
