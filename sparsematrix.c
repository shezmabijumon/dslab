#include<stdio.h>

struct tup{
    int row;
    int col;
    int val;
}tupA[10],tupB[10],Atrans[10],Btrans[10],sumtup[10];

int m,n;

void convert(int a[5][5],struct tup *tupA);
void display(struct tup *tupA);
void trans(struct tup *tupA,struct tup *Atrans);
void sum(struct tup *tupA,struct tup *tupB);

void main(){
    int i,j;
    int a[5][5],b[5][5];
    printf("enter the size of the matrix(mxn):");
    scanf("%d%d",&m,&n);
    printf("enter matrix 1:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter matrix 2:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    convert(a,tupA);
    convert(b,tupB);
    trans(tupA,Atrans);
    trans(tupB,Btrans);
    sum(tupA,tupB);
    
}
void convert(int a[5][5],struct tup *tupA){
    int i,j,k=1;
    tupA[0].row=m;
    tupA[0].col=n;
    tupA[0].val=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i][j]!=0){
                tupA[k].row=i;
                tupA[k].col=j;
                tupA[k].val=a[i][j];
                tupA[0].val++;
                k=k+1;
            }
        }
    }
    printf("\n");
    display(tupA);
}
void display(struct tup *tupA){
    int i,j,k;
    k=tupA[0].val;
    for(i=0;i<=k;i++){
        printf("%d  %d  %d\n",tupA[i].row,tupA[i].col,tupA[i].val);        
    }
    printf("\n");
}
void trans(struct tup *tupA,struct tup *Atrans){
    int t,current;
    int i,j;
    t=tupA[0].val;
    Atrans[0].row=tupA[0].col;
    Atrans[0].col=tupA[0].row;
    Atrans[0].val=t;
    if(t>0){
        current=1;
        for(i=0;i<=tupA[0].col;i++){
            for(j=1;j<=t;j++){
                if(tupA[j].col==i){
                    Atrans[current].row=tupA[j].col;
                    Atrans[current].col=tupA[j].row;
                    Atrans[current].val=tupA[j].val;
                    current++;
                }
            }
        }
    }
    display(Atrans);
}
void sum(struct tup *tupA,struct tup *tupB){
    int i,j,k=1;
    sumtup[0].row=m;
    sumtup[0].col=n;
    sumtup[0].val=0;
    i=1;
    j=1;
    while(i<=tupA[0].val && j<=tupB[0].val){
        if (tupA[i].row<tupB[j].row){
            sumtup[k].row=tupA[i].row;
            sumtup[k].col=tupA[i].col;
            sumtup[k].val=tupA[i].val;
            i++;
            k++;
        }
        if (tupA[i].row>tupB[j].row){
            sumtup[k].row=tupB[j].row;
            sumtup[k].col=tupB[j].col;
            sumtup[k].val=tupB[j].val;
            j++;
            k++;
        }
        if (tupA[i].row==tupB[j].row){
            if (tupA[i].row==tupB[j].row && tupA[i].col<tupB[j].col){
                sumtup[k].row=tupA[i].row;
                sumtup[k].col=tupA[i].col;
                sumtup[k].val=tupA[i].val;
                i++;
                k++;
            }
            if (tupA[i].row==tupB[j].row && tupA[i].col>tupB[j].col){
                sumtup[k].row=tupB[j].row;
                sumtup[k].col=tupB[j].col;
                sumtup[k].val=tupB[j].val;
                j++;
                k++;
            }
            if (tupA[i].row==tupB[j].row && tupA[i].col==tupB[j].col){
                sumtup[k].row=tupB[j].row;
                sumtup[k].col=tupB[j].col;
                sumtup[k].val=tupA[i].val+tupB[j].val;
                i++;
                j++;
                k++;
            }
        }
    }
    while(i<=tupA[0].val){
        sumtup[k].row=tupA[i].row;
        sumtup[k].col=tupA[i].col;
        sumtup[k].val=tupA[i].val;
        i++;
        k++;
    }
    while(j<=tupB[0].val){
        sumtup[k].row=tupB[j].row;
        sumtup[k].col=tupB[j].col;
        sumtup[k].val=tupB[j].val;
        j++;
        k++;        
    }
    sumtup[0].val=k-1;
	printf("\n");
	display(sumtup);
}