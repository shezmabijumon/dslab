#include <stdio.h>
#include <stdlib.h>

struct node{
    int coef;
    int expo;
    struct node *link;
};
struct node* insert(struct node *head,int c,int x);
struct node* create(struct node *head);
void print(struct node* head);
void polyadd(struct node *head1,struct node *head2);
void polymult(struct node *head1,struct node *head2);

void main(){
    struct node* head1=NULL;
    struct node* head2=NULL;
    struct node* head3=NULL;
    printf("POLYNOMIAL 1\n");
    head1 = create(head1);
    printf("POLYNOMIAL 2\n");
    head2 = create(head2);
    printf("\nPOLYNOMIAL 1\n");
    print(head1);
    printf("\nPOLYNOMIAL 2\n");
    print(head2);
    polymult(head1,head2);
    printf("\nSUM IS\n");
    polyadd(head1,head2);
}

struct node* insert(struct node *head,int c,int x){
    struct node *temp,*newp;
    newp=(struct node*)malloc(sizeof(struct node));
    newp->coef=c;
    newp->expo=x;
    newp->link=NULL;
    if (head==NULL || x > head->expo){

        newp->link=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->link!=NULL && temp->link->expo>=x)
            temp=temp->link;
        if(temp->expo==x){
            temp->coef=temp->coef+c;
        }
        else{   
            newp->link=temp->link;
            temp->link=newp;
        }
    }
    return head;
}
struct node* create(struct node *head){
    int n,i,c,ex;
    printf("enter number of terms in the polynomial:");
    scanf("%d",&n);
    printf("coef\texpo\n");
    for(i=0;i<n;i++){
        
        scanf("%d%d", &c,&ex);
        head = insert(head, c, ex);
    }
    return head;
}
void print(struct node* head){
    if (head == NULL)
        printf("No polynomial exists\n");
    else{
        struct node* temp = head; 
        while( temp!=NULL){
            if(temp->expo==0){
                printf("%d ",temp->coef);
            }
            else{
                printf("%dx^%d ",temp->coef,temp->expo);
            }
            temp=temp->link;
            if(temp!=NULL)
                printf("+ ");
            else
                printf("\n");
        }
    }
}
void polyadd(struct node *head1, struct node *head2) {
    int sc;
    struct node *ptr1 = head1;
    struct node *ptr2 = head2;
    struct node *head3 = NULL;

    while (ptr1 != NULL || ptr2 != NULL) {
        if (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1->expo == ptr2->expo) {
                sc = ptr1->coef + ptr2->coef;
                head3 = insert(head3, sc, ptr1->expo);
                ptr1 = ptr1->link;
                ptr2 = ptr2->link;
            } 
            else if (ptr1->expo > ptr2->expo) {
                head3 = insert(head3, ptr1->coef, ptr1->expo);
                ptr1 = ptr1->link;
            } 
            else {
                head3 = insert(head3, ptr2->coef, ptr2->expo);
                ptr2 = ptr2->link;
            }
        } 
        else if (ptr1 != NULL) {
            head3 = insert(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->link;
        } 
        else if (ptr2 != NULL) {
            head3 = insert(head3, ptr2->coef, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    print(head3);
}
/*void polyadd(struct node *head1,struct node *head2){
    int sc;
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *head3=NULL;
    while (ptr1!=NULL || ptr2!=NULL){
        if(ptr1->expo==ptr2->expo){
            sc=ptr1->coef+ptr2->coef;
            head3=insert(head3,sc,ptr1->expo);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        if(ptr1->expo>ptr2->expo){
            head3=insert(head3,ptr1->coef,ptr1->expo);
            ptr1=ptr1->link;
        }
        if(ptr1->expo<ptr2->expo){
            head3=insert(head3,ptr2->coef,ptr2->expo);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3=insert(head3,ptr1->coef,ptr1->expo);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL){
        head3=insert(head3,ptr2->coef,ptr2->expo);
        ptr2=ptr2->link;
    }    
    print(head3);     
}*/
void polymult(struct node *head1,struct node *head2){
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    struct node *head4=NULL;
    int res1,res2;
    if(head1==NULL || head2==NULL){
        printf("zero polynomial");
        return;
    }
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            res1=ptr1->coef*ptr2->coef;
            res2=ptr1->expo+ptr2->expo ;
            head4=insert(head4,res1,res2);
            ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
        ptr2=head2;
    }
    printf("\nPRODUCT IS\n");
    print(head4);
}