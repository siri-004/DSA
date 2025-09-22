#include<stdio.h>
int binarysearch(int a[],int n,int search){
	int low=0,high=n-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(search==a[mid]){
			return mid;
		}
		else if(search<a[mid]){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return -1;
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
	int result=binarysearch(a,n,search);
	if(result!=-1){
		printf("%d is found at %d location\n",a[result],result);
	}
	else{
		printf("Element not found");
	}
}