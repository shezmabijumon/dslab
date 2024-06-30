/*Write a C program to read student names stored in a file. Sort the names in alphabetical order
using bubble sort. Implement binary search to search for a given name. Implement sort and
search routines as separate functions.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int flag=-1;

void sort(char names[11][11],int n){
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++){
			if(strcmp(names[j],names[j+1])>0){
				char temp[11];
				strcpy(temp,names[j]);
				strcpy(names[j],names[j+1]);
				strcpy(names[j+1],temp);
			}
		}
	}
}

int search(char names[11][11],int n,char k[11]){
	int low=0,high=n;
	while(low<=high){
		int mid=(low+high)/2;
		int c=strcmp(names[mid],k);

		if(c==0)
			return mid;
		if(c>0)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

void main(){
	FILE *f;
	int n;
	char names[11][11],k[11];
	f=fopen("myfile.txt","r");
	if(f==NULL){
		printf("An error occured while opening the file ");
		exit(0);
	}
	n=0;
	while(fscanf(f,"%s",names[n])!=EOF && n<10){
		n++;
	}
	fclose(f);
	sort(names,n);
	printf("\nThe list of sorted names is :\n");
	for(int i=0;i<n;i++)
		printf("%s\n",names[i]);
	printf("Enter the name to be searched for: ");
	scanf("%s",k);
	flag=search(names,n,k);
	if(flag==-1){
		printf("The element is not found\n");
	}
	else{
		printf("The name %s has been found in the list at position %d\n",k,flag+1);
	}
}