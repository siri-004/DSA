#include<stdio.h>
int main(){
    int arr1[10],arr2[10],arr3[20];
    int n1,n2,m,index=0;
    printf("Enter the number of elements in array 1: ");
    scanf("%d",&n1);
    printf("The elements of array 1 are: ");
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter the number of elements in array 2: ");
    scanf("%d",&n2);
    printf("The elements of array 2 are: ");
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    m=n1+n2;
    for(int i=0;i<n1;i++){
        arr3[index]=arr1[i];
        index++;
    }
    for(int i=0;i<n2;i++){
        arr3[index]=arr2[i];
        index++;
    }
    printf("The merged array:\n");
    for(int i=0;i<m;i++){
        printf("%d ",arr3[i]);
    }
    return 0;
}