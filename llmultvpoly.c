#include<stdio.h>
#include<stdlib.h>

struct node{
    int coef;
    int xexp;
    int yexp;
    struct node *link;
};
struct node* insert(struct node *head,int c,int x,int y);
struct node* create(struct node *head);
void print(struct node* head);
void polyadd(struct node* head1,struct node* head2);

void main(){
    struct node *h1=NULL;
    struct node *h2=NULL;
    struct node *h3=NULL;
    printf("POLYNOMIAL 1\n");
    h1 = create(h1);
    printf("POLYNOMIAL 2\n");
    h2 = create(h2);
    printf("\nPOLYNOMIAL 1\n");
    print(h1);
    printf("\nPOLYNOMIAL 2\n");
    print(h2);
}
struct node* insert(struct node *head,int c,int x,int y){
    struct node *new,*ptr;
    new=(struct node*)malloc(sizeof(struct node));
    new->coef=c;
    new->xexp=x;
    new->yexp=y;
    new->link=NULL;
    if(head==NULL || ((x+y)>(head->xexp+head->yexp))){
        new->link=head;
        head=new;
    }
    else{
        ptr=head;
        while(ptr->link!=NULL && ((ptr->xexp+ptr->yexp)>=(x+y))){
            ptr=ptr->link;
        }
        if((ptr->xexp+ptr->yexp)==(x+y)){
            if(ptr->xexp==x){
                ptr->coef=ptr->coef+c;
            }
            new->link=ptr->link;
            ptr->link=new;
        }
        else{
            new->link=ptr->link;
            ptr->link=new;
        }
    }
    return head;
}
struct node* create(struct node *head){
    int n,i,c,x,y;
    printf("enter number of terms in the polynomial:");
    scanf("%d",&n);
    printf("coef\tx expo\ty expo\n");
    for(i=0;i<n;i++){        
        scanf("%d%d%d", &c,&x,&y);
        head = insert(head, c, x,y);
    }
    return head;
}
void print(struct node* head){
    if (head == NULL)
        printf("No polynomial exists\n");
    else{
        struct node* temp = head; 
        while( temp!=NULL){
            if(temp->xexp==0 && temp->yexp==0){
                printf("%d ",temp->coef);
            }
            else if(temp->yexp==0){
                printf("%dx^%d ",temp->coef,temp->xexp);
            }
            else if(temp->xexp==0){
                printf("%dy^%d ",temp->coef,temp->yexp);
            }
            else{
                printf("%dx^%dy^%d ",temp->coef,temp->xexp,temp->yexp);
            }
            temp=temp->link;
            if(temp!=NULL)
                printf("+ ");
            else
                printf("\n");
        }
    }
}
void polyadd(struct node* head1,struct node* head2){
    int sc;
    struct node* h3=NULL;
    struct node* ptr1=h1;
    struct node* ptr2=h2;
    struct node* ptr3=h3;
    while(ptr1!=NULL && ptr2!=NULL){
        if((ptr1->xexp+ptr1->yexp)>(ptr2->xexp+ptr2->yexp)){
            h3=insert(h3,ptr1->coef,ptr1->xexp,ptr1->yexp)
            ptr1=ptr1->link;
        }
        if((ptr1->xexp+ptr1->yexp)<>>(ptr2->xexp+ptr2->yexp)){
            h3=insert(h3,ptr2->coef,ptr2->xexp,ptr2->yexp)
            ptr2=ptr2->link;
        }
    }
     
}