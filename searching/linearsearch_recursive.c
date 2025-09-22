#include<stdio.h>
int linearsearch(int a[],int n,int search,int index);
int main(){
	int n,search,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements into the array: ");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&search);
	int result=linearsearch(a,n,search,0);
	if(result!=-1){
		printf("%d is found at %d location\n",a[result],result);
	}
	else{
		printf("Element not found\n");
	}
}
int linearsearch(int a[],int n,int search,int index){
	if(index>=n-1){
		return -1;
	}
	if(a[index]==search){
		return index;
	}
	return linearsearch(a,n,search,index+1);
}