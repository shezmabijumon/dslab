#include <stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void main(){
    int choice;
    printf("LINKED LIST OPERATIONS\n");
    do{
        printf("\n MENU \n1.Create \n2.Display \n3.Insert at the beginning \n4.Insert at the end \n5.Insert at specified position\n");
        printf("6.Delete from beginning\n7.Delete from the end\n8.Delete from specified position\n9.Exit \n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)        {
            case 1:
            create();
            break;
            case 2:
            display();
            break;
            case 3:
            insert_begin();
            break;
            case 4:
            insert_end();
            break;
            case 5:
            insert_pos();
            break;
            case 6:
            delete_begin();
            break;
            case 7:
            delete_end();
            break;
            case 8:
            delete_pos();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf(" Wrong Choice:\n");
            break;
        }
    }while(choice!=9);
}
void create(){
    struct node *newnode,*ptr;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("No memory space:");
        exit(0);
    }
    printf("\nEnter the data value for the node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}
void display(){
    struct node *ptr;
    if(head==NULL){
        printf("\nList is empty:\n");
        return;
    }
    else{
        ptr=head;
        printf("\nThe List elements are: ");
        while(ptr!=NULL){
            printf("%d ",ptr->data );
            ptr=ptr->next;
        }
    }
}
void insert_begin(){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\nNo Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:" );
    scanf("%d",&newnode->data);
    newnode->next =NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}
void insert_end(){
    struct node *newnode,*ptr;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("No Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:" );
    scanf("%d",&newnode->data );
    newnode->next =NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        ptr=head;
        while(ptr->next !=NULL){
            ptr=ptr->next ;
        }
        ptr->next =newnode;
    }
}
void insert_pos(){
    struct node *ptr,*newnode;
    int i,pos;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("\n No memory space\n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted:");
    scanf("%d",&pos);
    printf("\nEnter the data value of the node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(pos==0){
        newnode->next=head;
        head=newnode;
    }
    else{
        for(i=0,ptr=head;i<pos-1;i++){
            ptr=ptr->next;
            if(ptr==NULL){
                printf("\nPosition not found\n");
                return;
            }
        }
        newnode->next =ptr->next ;
        ptr->next=newnode;
    }
}
void delete_begin(){
    struct node *ptr;
    if(head==NULL){
        printf("\nList is Empty:\n");
        return;
    }
    else{
        printf("\nThe deleted element is: %d",head->data);
        head=head->next;
    }
}
void delete_end(){
    struct node *newnode,*ptr;
    if(head==NULL){
        printf("\nList is Empty:");
        exit(0);
    }
    else if(head->next ==NULL){
        printf("\nThe deleted element is:%d",head->data);
        head=NULL;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            newnode=ptr;
            ptr=ptr->next;
        }
        newnode->next=NULL;
        printf("\nThe deleted element is:%d",ptr->data);
        free(ptr);
    }
}
void delete_pos(){
    int i,pos;
    struct node *newnode,*ptr;
    if(head==NULL){
        printf("\nThe List is Empty:\n");
        exit(0);
    }
    else{
        printf("\nEnter the position of the node to be deleted:");
        scanf("%d",&pos);
        if(pos==0){
            ptr=head;
            head=head->next ;
            printf("\nThe deleted element is:%d",ptr->data );
            free(ptr);
        }
        else{
            ptr=head;
            for(i=0;i<pos;i++){
                newnode=ptr;
                ptr=ptr->next;
                if(ptr==NULL){
                    printf("\nPosition not Found:\n");
                    return;
                }
            }
            newnode->next =ptr->next ;
            printf("\nThe deleted element is:%d",ptr->data );
            free(ptr);
        }
    }
}