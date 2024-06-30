#include<stdio.h>

int dq[10];
int n,f=-1,r=-1;

void insertf(int x){
    int next;
    if (f==-1){
        next=0;
    }
    else if(f==0){
        next=n-1;
    }
    else{
        next=f-1;
    }
    if(next==r){
        printf("queue is full");
        return;
    }
    if(f==-1){
        r=0;
    }
    f=next;
    printf("f is %d",f);
    dq[f]=x;

}
void insertr(int x){
    if ((r+1)%n==f){
        printf("queue is full\n");
        return;
    }
    if(f==-1&&r==-1){
        f=0;
        r++;        
        dq[r]=x;
    }
    else if(r==n-1 && f!=0){
        r=0;
        dq[r]=x;
    }
    else{
        r=((r+1)%n);
        dq[r]=x;
    }
}
void deletef(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    printf("deleted element is %d",dq[f]);
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
void deleter(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    printf("deleted element is %d",dq[r]);
    if(r==0){
        r=n-1;
    }
    else if(r==f){
        r=-1;
        f=-1;
    }
    else{
        r=r-1;
    }
}
void display(){
    if(f==-1){
        printf("queue is empty");
        return;
    }
    if(f<=r){
        for(int i=f;i<=r;i++){
            printf("%d  ",dq[i]);
        }
    }
    else{
        for(int i=0;i<=r;i++){
            printf("%d  ",dq[i]);
        }
        for(int i=f;i<n;i++){
            printf("%d  ",dq[i]);
        }
    }
}

void main(){
    int ch,x;
    printf("enter size of queue:");
    scanf("%d",&n);
    do{
        printf("\n1.INSERT FRONT\n2.INSERT END\n3.DELETE FRONT\n4.DELETE END\n5.DISPLAY\n6.EXIT\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("enter element:");
            scanf("%d",&x);
            insertf(x);
            break;
            case 2:
            printf("enter element:");
            scanf("%d",&x);
            insertr(x);
            break;
            case 3:
            deletef();
            break;
            case 4:
            deleter();
            break;
            case 5:
            display();
            break;
            case 6:
            printf("exiting..");
            break;
            default:
            printf("invalid choice\n");
            break;
        }
    }while (ch!=4);
}