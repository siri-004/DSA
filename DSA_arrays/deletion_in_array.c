#include<stdio.h>
int main(){
    int n,pos,arr[10];
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    printf("\nEnter the elements of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the position of the element which has to be deleted:");
    scanf("%d",&pos);
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;
    printf("\nThe array elements after deleting an element :");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
}