#include<stdio.h>
void selectionSort(int a[],int n){
    int temp,min,i;
    for(i=0;i<n;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        if(min!=i){
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    }
}
void printArray(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter the size of an array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements into the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Before Sorting: ");
    printArray(a,n);
    selectionSort(a,n);
    printf("After Sorting: ");
    printArray(a,n);
}