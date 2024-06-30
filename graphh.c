#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct adjacent{                //represent adjacent vertices of a node
    struct node *llink;
    struct adjacent *rlink;
};

struct node{                    //represents a vertex
    int vertex,index;
    struct node *nlink;         //link to next node
    struct adjacent *alink;     //link to adjacent node
} *head=NULL;                   //Pointer to the head node of the graph.

struct dfslist{                 //represents a list used during DFS and BFS traversals
    int data;
    struct dfslist *link;
} *list=NULL,*set=NULL;

struct node *stack[20];         //DFS
int top =-1;
void push(struct node *x){
    top++;
    stack[top]=x;
}
struct node *pop(){
    struct node *del=stack[top];
    top--;
    return del;
}

struct node *queue[20];         //BFS
int f=-1,r=-1;
void enqueue(struct node *x){
    if (f==-1){
        f=0;
        r=0;
    }
    else{
        r++;
    }
    queue[r]=x;
}
struct node* dequeue(){
    struct node *del=queue[f];
    f++;
    return del;
}

void insertvertex(int,int);
void insertadjvertex(int,int);
void displaylist();
void displaymatrix(int);
void dfs(struct node*);
void displaydfs();

void main(){
    int n,i,j,nadj,adjver,A[20];
    printf("enter no.of vertices: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("enter the vertex %d:",(i+1));
        scanf("%d",&A[i]);
        insertvertex(A[i],i);
    }
    for(i=0;i<n;i++){
        printf("enter no.of vertices directed from %d: ",A[i]);
        scanf("%d",&nadj);
        for(j=0;j<nadj;j++){
            printf("enter the directed vertex %d",(j+1));
            scanf("%d",&adjver);
            insertadjvertex(A[i],adjver);
        }
    }
    displaylist();
    displaymatrix(n);
    dfs(head);
    bfs(head);
}

void insertvertex(int v,int ind){
    struct node *new,*ptr;
    new=(struct node *)malloc(sizeof(struct node));
    new->vertex=v;
    new->index=ind;
    new->nlink=NULL;
    new->alink=NULL;
    if (head==NULL){
        head=new;
        return;
    }
    ptr=head;
    while(ptr->nlink!=NULL){
        ptr=ptr->nlink;
    }
    ptr->nlink=new;
}
void insertadjvertex(int vert,int adjvert){
    struct node *ptr,*curr;
    struct adjacent *new,*str;
    new=(struct adjacent*)malloc(sizeof(struct adjacent));
    ptr=head;
    curr=head;
    while(curr!=NULL){
        if(curr->vertex==vert){
            str=curr->alink;
            break;
        }
        curr=curr->nlink;
    }
    while(ptr!=NULL){
        if(ptr->vertex==adjvert){
            new->llink=ptr;
            new->rlink=NULL;
            break;
        }
        ptr=ptr->nlink;
    }
    if(curr->alink==NULL){
        curr->alink=new;
        return;
    }
    while(str->rlink!=NULL){
        str=str->rlink;
    }
    str->rlink=new;
}
void displaylist(){
    struct node *ptr;
    struct adjacent *str;
    ptr=head;
    printf("\nThe Adjacency list \n");
    while(ptr!=null){
        str=ptr->alink;
        printf("%d[%d]",ptr->vertex,ptr->index);
        while(str!=null){
            printf("-> %d",(str->llink)->vertex);
            str=str->rlink;
        }
        ptr=ptr->nlink;
    }
}
void displaymatrix(int n){
    struct node *ptr;
    struct adjacent *str;
    int A[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A[i][j]==0;
        }
    }
    ptr=head;
    while(ptr!=NULL){
        str=ptr->alink;
        while(str!=NULL){
            A[ptr->index][(str->llink)->index]=1;
            str=str->rlink;
        }
        ptr=ptr->nlink;
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d",A[i][j]);
        }
        printf("\n");
    }
}
void dfs(struct node* p){
    struct node *ptr;
    struct adjacent *str;
    struct dfslist *new,*qtr,*prev;
    int c=0;
    new=(struct dfslist *)malloc(sizeof(struct dfslist));
    ptr=p;
    qtr=list;
    new->data=ptr->vertex;
    new->link=NULL;
    if(qtr==NULL){
        list=new;
        while(str!=NULL){
            push(str->llink);
            str=str->rlink;
        }
    }
    else{
        while(qtr!=NULL){
            if(qtr->data==new->data){
                c=1;
                break;
            }
            else{
                prev=qtr;
                qtr=qtr->link
                c=0;
            }
        }
        if(c==0){
            qtr=prev;
            qtr->link=new;
            while(str!=NULL){
                push(str->llink);
                str=str->rlink;
            }
        }
    }
    if(top==-1){
        displaydfs();
    }
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