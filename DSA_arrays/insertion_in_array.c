#include<stdio.h>
int main(){
    int n,num,pos,arr[10];
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the elments of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the number to be inserted: ");
    scanf("%d",&num);
    printf("\nEnter the position at which the number has to be inserted:");
    scanf("%d",&pos);
    for(int i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=num;
    n=n+1;
    printf("The array after inserting the element is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}