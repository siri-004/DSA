#include<stdio.h>
void BubbleSort(int a[],int n){
    int temp,flag;
    for(int i=0;i<n;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
            if(flag==0){
                break;
            }
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
    BubbleSort(a,n);
    printf("After Sorting: ");
    printArray(a,n);
}
