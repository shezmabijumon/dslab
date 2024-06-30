#include<stdio.h>

struct poly{
    int c;
    int x1;
    int x2;
};
int n1,n2;
int n3;
void addpoly(struct poly *p1,struct poly *p2);
void display(struct poly *p,int n);

void main(){
    
    int i;
    struct poly p1[10],p2[10];
    printf("POLYNOMIAL 1\n");
    printf("enter no.of terms:");
    scanf("%d",&n1);   
    printf("coef\texp 'x'\texp 'y'\n"); 
    for(i=0;i<n1;i++){
        scanf("%d%d%d",&p1[i].c,&p1[i].x1,&p1[i].x2);
    }    
    printf("POLYNOMIAL 2\n");
    printf("enter no.of terms:");
    scanf("%d",&n2);
    n3=n1+n2;
    printf("coef\texp 'x'\texp 'y'\n");
    for(i=0;i<n2;i++){
        scanf("%d%d%d",&p2[i].c,&p2[i].x1,&p2[i].x2);
    }
    addpoly(p1,p2);        
}
void addpoly(struct poly *p1,struct poly *p2){
    struct poly p3[20];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if((p1[i].x1+p1[i].x2)>(p2[j].x1+p2[j].x2)){
            p3[k].c=p1[i].c;
            p3[k].x1=p1[i].x1;
            p3[k].x2=p1[i].x2;
            i++;
            k++;
        }
        if((p1[i].x1+p1[i].x2)<(p2[j].x1+p2[j].x2)){
            p3[k].c=p2[j].c;
            p3[k].x1=p2[j].x1;
            p3[k].x2=p2[j].x2;
            j++;
            k++;
        }
        if((p1[i].x1+p1[i].x2)==(p2[j].x1+p2[j].x2)){
            if(p1[i].x1==p2[j].x1){
                p3[k].c=p1[i].c+p2[j].c;
                p3[k].x1=p1[i].x1;
                p3[k].x2=p1[i].x2;
                i++;
                j++;
                k++;
            }
            else{
                p3[k].c=p1[i].c;
                p3[k].x1=p1[i].x1;
                p3[k].x2=p1[i].x2;
                i++;
                k++;
                p3[k].c=p2[j].c;
                p3[k].x1=p2[j].x1;
                p3[k].x2=p2[j].x2;
                j++;
                k++;
            }
        }
    }
    while(i<n1){
        p3[k].c=p1[i].c;
        p3[k].x1=p1[i].x1;
        p3[k].x2=p1[i].x2;
        i++;
        k++;
    }
    while(j<n2){
        p3[k].c=p2[j].c;
        p3[k].x1=p2[j].x1;
        p3[k].x2=p2[j].x2;
        j++;
        k++;
    }
    printf("SUM IS: ");
    display(p3,k);
}
void display(struct poly *p,int n){
    int i;
    for(i=0;i<n-1;i++){
        if(p[i].x1==0 && p[i].x2==0){
            printf("%d + ",p[i].c);
        }
        else if(p[i].x1==0 && p[i].x2!=0){
            printf("%dy^%d + ",p[i].c,p[i].x2);
        }
        else if(p[i].x2==0 && p[i].x1!=0){
            printf("%dx^%d + ",p[i].c,p[i].x1);
        }
        else{
            printf("%dx^%dy^%d + ",p[i].c,p[i].x1,p[i].x2);
        }
    }
    if(p[i].x1==0 && p[i].x2==0){
            printf("%d ",p[i].c);
    }
    else if(p[i].x1==0 && p[i].x2!=0){
        printf("%dy^%d ",p[i].c,p[i].x2);
    }
    else if(p[i].x2==0 && p[i].x1!=0){
        printf("%dx^%d ",p[i].c,p[i].x1);
    }
    else{
        printf("%dx^%dy^%d ",p[i].c,p[i].x1,p[i].x2);
    }
}