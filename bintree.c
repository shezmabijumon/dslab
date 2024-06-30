#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

struct node *root=NULL;
struct node *GetNode();
struct node *SearchNode(struct node *p,int key);
void InsertNode(int x);
void InorderTrav(struct node* ptr);
void PreorderTrav(struct node* ptr);
void PostorderTrav(struct node* ptr);
struct node *DeleteNode(struct node *ptr,int x);

void main(){
    int choice,x;
    printf("\nBinary Tree using Linked List\n");
    printf("1. Insert a new node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Post order traversal\n");
    printf("5. Delete a node\n6.exit\n");
    do{
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element : ");
            scanf("%d",&x);
            InsertNode(x);
            break;
            case 2:
            InorderTrav(root);
            break;
            case 3:
            PreorderTrav(root);
            break;
            case 4:
            PostorderTrav(root);
            break;
            case 5:
            printf("Enter the element to be deleted : ");
            scanf("%d",&x);
            DeleteNode(root,x);
            break;
            case 6:
            break;
            default:
            printf("\n.....\n");
        }
        printf("\n\n");
    }while(choice!=6);
    printf("Thank You\n\n");
}

struct node *GetNode(){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if (ptr==NULL){
        printf("memory not available");
        exit(0);
    }
    ptr->llink=NULL;
    ptr->rlink=NULL;
    return ptr;
}
struct node *SearchNode(struct node *p,int key){
    struct node *ptr=NULL;
    if (p->data != key){
        if (p->llink!=NULL){
            ptr=SearchNode(p->llink,key);
            if(ptr!=NULL){
                return ptr;
            }
        }
        else{
            return NULL;
        }
        if (p->rlink!=NULL){
            ptr=SearchNode(p->rlink,key);
            if(ptr!=NULL){
                return ptr;
            }
        }
        else{
            return NULL;
        }
    }
    else{
        return p;
    }
}
void InsertNode(int x){
    if (root==NULL){
        root=GetNode();
        root->data=x;
        return;
    }
    struct node *ptr,*new;
    int key;
    printf("Enter the parent node to which new node to be inserted : ");
    scanf("%d",&key);
    ptr=SearchNode(root,key);
    if (ptr==NULL){
        printf("key not found");
        return;
    }
    if(ptr->llink==NULL){
        new=GetNode();
        ptr->llink=new;
        new->data=x;
    }
    else if(ptr->rlink==NULL){
        new=GetNode();
        ptr->rlink=new;
        new->data=x;
    }
    else{
        printf("not possible");
    }
}
void InorderTrav(struct node* ptr){
    if(ptr!=NULL){
        InorderTrav(ptr->llink);
        printf("%d ",ptr->data);
        InorderTrav(ptr->rlink);
    }
}
void PreorderTrav(struct node* ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        PreorderTrav(ptr->llink);
        PreorderTrav(ptr->rlink);
    }
}
void PostorderTrav(struct node* ptr){
    if(ptr!=NULL){
        PostorderTrav(ptr->llink);
        PostorderTrav(ptr->rlink);
        printf("%d ",ptr->data);
    }
}
struct node *DeleteNode(struct node *ptr,int x){
    struct node *temp;
    if (ptr!=NULL){
        ptr->llink=DeleteNode(ptr->llink,x);
        ptr->rlink=DeleteNode(ptr->rlink,x);
        if(ptr->llink==NULL && ptr->rlink==NULL && ptr->data==x){
            temp=ptr;
            free(temp);
            ptr=NULL;
            return NULL;
        }
        return ptr;
    }
    else{
        return NULL;
    }
}