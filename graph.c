#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct adjacent{
    struct node *llink;
    struct adjacent* rlink;
};
struct node{
    int vertex;
    int index;
    struct node* nlink;
    struct adjacent* alink;
} *head=NULL;

struct dfslist{
    int data;
    struct dfslist* link;
} *list=NULL,*set=NULL;

struct node *stack[20];
int top=-1;
void push(struct node* x){
    top++;
    stack[top]=x;
}
struct node* pop(){
    struct node *x;
    x=stack[top];
    top--;
    return x;
}

struct node* queue[20];
int front=-1,rear=-1;
void insert(struct node* x){
    rear++;
    queue[rear]=x;
}
struct node* delete(){
    struct node *x;
    x=queue[front];
    front++;    
    return x;
}

void insertvertex(int,int);
void insertadjvertex(int,int);
void displaylist();
void displaymatrix(int);
void dfs(struct node *);
void displaydfs();
void bfs(struct node *);
void displaybfs();

int main(){
    int n,i,j,ver,adj,adver,A[20];
    //struct dfslist *qtr;
    printf("\nEnter the number of vertices : ");
    scanf("%d",&n);
    printf("\n");
    for(i=0; i<n; i++){
        printf("Enter the vertex %d : ",i+1);
        scanf("%d",&ver);
        A[i]=ver;
        insertvertex(ver,i);
    }
    for(i=0; i<n; i++)    {
        printf("\nNo of vertices directed from %d : ",A[i]);
        scanf("%d",&adj);
        for(j=0; j<adj; j++){
            printf("Enter the directed vertex %d : ",j+1);
            scanf("%d",&adver);
            insertadjvertex(adver,A[i]);
        }
    }
    displaylist();
    displaymatrix(n);
    dfs(head);
    bfs(head);
}
void insertvertex(int x,int y){
    struct node *ptr,*temp;
    temp = (struct node *)malloc(sizeof(struct node));
    ptr=head;
    temp->vertex=x;
    temp->index=y;
    temp->nlink=NULL;
    temp->alink=NULL;
    if(head==NULL){
        head = temp;
        return;
    }
    while(ptr->nlink != NULL)
        ptr = ptr->nlink;
    ptr->nlink=temp;
}
void insertadjvertex(int x,int y){
    struct node *ptr,*curr;
    struct adjacent *str,*temp;
    temp = (struct adjacent *)malloc(sizeof(struct adjacent));
    ptr=head;
    curr=head;
    while(curr != NULL){
        if(curr->vertex == y)
        {
            str=curr->alink;
            break;
        }
        curr = curr->nlink;
    }
    while(ptr != NULL)
    {
        if(ptr->vertex == x)
        {
            temp->llink = ptr;
            temp->rlink = NULL;
            break;
        }
        ptr = ptr->nlink;
    }
    if(curr->alink == NULL)
    {
        curr->alink = temp;
        return;
    }
    while(str->rlink != NULL)
        str=str->rlink;
    str->rlink=temp;
}
void displaylist(){
    struct node *ptr;
    struct adjacent *str;
    ptr=head;
    printf("\nThe Adjacency list \n");
    while(ptr != NULL){
        str=ptr->alink;
        printf("\n%d[%d]",ptr->vertex,ptr->index);
        while(str != NULL){
            printf(" -> %d",(str->llink)->vertex);
            str=str->rlink;
        }
        ptr = ptr->nlink;
    }
    printf("\n");
}
void displaymatrix(int x){
    struct node *ptr;
    struct adjacent *str;
    int A[x][x];
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            A[i][j]=0;
        }
    }
    ptr=head;
    printf("\nThe Adjacency matrix \n\n");
    while(ptr != NULL){
        str=ptr->alink;
        while(str != NULL){
            A[ptr->index][str->llink->index] = 1;
            str=str->rlink;
        }
        ptr = ptr->nlink;
    }
    for(int i=0; i<x; i++){
        for(int j=0; j<x; j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void dfs(struct node *x){
    struct node *ptr;
    struct adjacent *str;
    struct dfslist *temp,*qtr,*prev;
    ptr=x;
    qtr=list;
    temp = (struct dfslist *)malloc(sizeof(struct dfslist*));
    temp->data=ptr->vertex;
    temp->link=NULL;
    int count=0,i=1;
    str=ptr->alink;
    if(list == NULL){
        list = temp;
        while(str != NULL){
            push(str->llink);
            str=str->rlink;
        }
    }
    else{
        while(qtr != NULL){
            if(qtr->data == temp->data){
                count = 1;
                break;
            }
            else{
                prev=qtr;
                qtr=qtr->link;
                count=0;
            }
        }
        if(count==0){
            qtr=prev;
            qtr->link = temp;
            while(str != NULL){
                push(str->llink);
                str=str->rlink;
            }
        }
    }
    if(top == -1)
        displaydfs();
    else{
        ptr=pop();
        dfs(ptr);
    }
}
void displaydfs(){
    printf("\nThe DFS traversal is: ");
    struct dfslist *qtr;
    qtr=list;
    while(qtr != NULL){
        printf("%d ",qtr->data);
        qtr=qtr->link;
    }
    printf("\n");
}
void bfs(struct node *x){
    struct node *ptr;
    struct adjacent *str;
    struct dfslist *temp,*qtr,*prev;
    ptr=x;
    qtr=set;
    temp = (struct dfslist *)malloc(sizeof(struct dfslist*));
    temp->data=ptr->vertex;
    temp->link=NULL;
    int count=0,i=1;
    str=ptr->alink;
    if(set == NULL){
        set = temp;
        while(str != NULL){
            insert(str->llink);
            str=str->rlink;
        }
    }
    else{
        while(qtr != NULL){
            if(qtr->data == temp->data){
                count = 1;
                break;
            }
            else{
                prev=qtr;
                qtr=qtr->link;
            }
        }
        if(count==0){
            qtr=prev;
            qtr->link = temp;
            while(str != NULL){
                insert(str->llink);
                str=str->rlink;
            }
        }
    }
    if(front == rear)
        displaybfs();
    else{
        ptr=delete();
        bfs(ptr);
    }
}
void displaybfs(){
    printf("\nThe BFS traversal is: ");
    struct dfslist *qtr;
    qtr=set;
    while(qtr != NULL){
        printf("%d ",qtr->data);
        qtr=qtr->link;
    }
    printf("\n");
}
