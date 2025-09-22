#include<stdio.h>
int binarysearch(int a[],int n,int search,int low,int high){
	int mid;
	if(low>=high){
		return -1;
	}
	mid=(low+high)/2;
	if(a[mid]==search){
		return mid;
	}
	else if(search<a[mid]){
		return binarysearch(a,n,search,low,mid-1);
	}
	else {
		return binarysearch(a,n,search,mid+1,high);
	}
}
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
	int result=binarysearch(a,n,search,0,n-1);
	if(result!=-1){
		printf("%d is found at %d location\n",a[result],result);
	}
	else{
		printf("Element not found");
	}
}