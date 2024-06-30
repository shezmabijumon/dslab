//I N C O M P L E T E
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *head=NULL;
int max;

void main(){
    int ch;
    do{
        printf("\n1.INSERT FRONT\n2.INSERT END\n3.INSERT AT POS\n4.DELETE FRONT\n5.DELETE END\n6.DELETE FROM POS\n7.DISPLAY\n8.EXIT\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            insertf();
            break;
            case 2:
            inserte();
            break;
            case 3:
            insertany();
            break;
            case 4:
            deletef();
            break;
            case 5:
            deleter();
            break;
            case 6:
            break;
            case 7:
            display();
            break;
            case 8:
            printf("exiting..");
            break;
            default:
            printf("invalid choice\n");
            break;
        }
    }while (ch!=4);
}

void insertf(){
    struct node *new,*ptr;
    int x;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("no memory space available\n");
        exit(0);
    }
    printf("enter data of node:");
    scanf("%d",&x);
    new->data=x;
    new->link=null;
    if(head==NULL){
        head=new;
        return;
    }
    ptr=head;
    head=new;
    new->link=ptr;
}
void inserte(){
    struct node *new,*ptr;
    int x;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("no memory space available\n");
        exit(0);
    }
    printf("enter data of node:");
    scanf("%d",&x);
    new->data=x;
    new->link=null;
    if(head==NULL){
        head=new;
        return;
    }
    ptr=head;
    while(ptr->link!=null){
        ptr=ptr->link;
    }
    ptr->link=new;
}
void insertany(){
    struct node *new,*ptr;
    int i,x,pos;
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL){
        printf("no memory space available\n");
        exit(0);
    }
    printf("enter pos:");
    scanf("%d",&pos);
    printf("enter data of node:");
    scanf("%d",&x);
    new->data=x;
    new->link=null;
    if(pos==0){
        new->link=head;
        head=new;
        return;
    }
    ptr=head;
    for(i=0;i<pos;i++){
        ptr=ptr->link;
        if(ptr==NULL){
            printf("\nPosition not found\n");
            return;
        }
    }
    new->link=ptr->link;
    ptr->link=new;

}