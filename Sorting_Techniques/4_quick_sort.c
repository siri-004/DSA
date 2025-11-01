#include<stdio.h>
void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int lb,int ub){
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while(a[end]>pivot){
            end--;
        }
        if(start<end){
            swap(&a[start],&a[end]);
        }
    }
    swap(&a[lb],&a[end]);
    return end;
}
void quickSort(int a[],int lb,int ub){
    if(lb<ub){
        int l=partition(a,lb,ub);
        quickSort(a,lb,l-1);
        quickSort(a,l+1,ub);
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
    quickSort(a,0,n-1);
    printf("After Sorting: ");
    printArray(a,n);
}