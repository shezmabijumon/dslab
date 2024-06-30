#include<stdio.h>

int n,f=-1,r=-1;

struct pq{
    int ele;
    int pri;
}p[10];

void enqueue(){
    int x,num;
    if(r==n-1){
        printf("queue is full");
        return;
    }
    printf("enter element:");
    scanf("%d",&num);
    printf("enter priority:");
    scanf("%d",&x);
    if(f==-1 && r==-1){
        f=0;
        r=0;
    }
    else{
        r=r+1;
    }
    p[r].ele=num;
    p[r].pri=x;

}
void dequeue(){
    if(f==-1){
        printf("queue is empty\n");
        return;
    }
    printf("deleted element is %d\n",p[f].ele);
	if(r==f){
		r=-1;
		f=-1;
	}
	else{
		f=f+1;
    }
}
void display(){
	int i;
	if(r==-1 && f==-1){
		printf("Queue is empty\n ");
		return;
	}
	for(i=f;i<=r;i++)
		printf("%d   ",p[i].ele);
	return;
}


void main(){
    int ch,x;
    int i,j,t1,t2;
    printf("enter size of queue:");
    scanf("%d",&n);
    do{
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n");
        printf("enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:            
            enqueue(x);
            for(i=f;i<=r;i++){
                for(j=f;j<r;j++){
                    if(p[j].pri<p[j+1].pri){
                        t1=p[j].ele;
                        p[j].ele=p[j+1].ele;
                        p[j+1].ele=t1;
                        t2=p[j].pri;
                        p[j].pri=p[j+1].pri;
                        p[j+1].pri=t2;
                    }
                }
            }
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