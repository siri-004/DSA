#include<stdio.h>
void linearsearch(int a[],int n,int search);
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
	linearsearch(a,n,search);
	return 0;
}
void linearsearch(int a[],int n,int search){
	int found=0,i;
	for(i=0;i<n;i++){
		if(a[i]==search){
			printf("%d is found at %d location",a[i],i);
			found=1;
			break;
		}
	}
	if(found==0){
		printf("Element not found\n");
	}
}