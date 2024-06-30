#include<stdio.h>

int q[10];
int n,f=-1,r=-1;

void enqueue(int x){
    if ((r+1)%n==f){
        printf("queue is full\n");
        return;
    }
    if(f==-1&&r==-1){
        f=0;
        r++;        
        q[r]=x;
    }
    else if(r==n-1 && f!=0){
        r=0;
        q[r]=x;
    }
    else{
        r=((r+1)%n);
        q[r]=x;
    }
}
void dequeue(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    printf("deleted element is %d",q[f]);
    if(f==r){
        f=-1;
        r=-1;
    }
    else if(f==n-1){
        f=0;
    }
    else{
        f++;
    }
}
void display(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    if(f<=r){
        for(int i=f;i<=r;i++){
            printf("%d  ",q[i]);
        }
    }
    else{
        for(int i=0;i<=r;i++){
            printf("%d  ",q[i]);
        }
        for(int i=f;i<n;i++){
            printf("%d  ",q[i]);
        }
    }
}

void main(){
    int ch,x;
    printf("enter size of queue:");
    scanf("%d",&n);
    do{
        printf("\n1.INSERT\n2.pDELETE\n3.DISPLAY\n4.EXIT\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter element:");
            scanf("%d",&x);
            enqueue(x);
            break;
            case 2:
            dequeue();
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