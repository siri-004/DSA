#include<stdio.h>
void merge(int a[],int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int k=low;
    int temp[100];
    while(i<=mid&&j<=high){
        if(a[i]<=a[j]){
            temp[k]=a[i];
            i++;
        }
        else{
            temp[k]=a[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        temp[k]=a[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++){
        a[i]=temp[i];
    }
}
void mergeSort(int a[],int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
    mergeSort(a,0,n-1);
    printf("After Sorting: ");
    printArray(a,n);
}