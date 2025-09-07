#include<stdio.h>
int stack[10];
int top=-1;
void push(int val){
    top++;
    stack[top]=val;
}
int pop(){
    int x= stack[top];
    top--;
    return x;
}
int main(){
    int n,arr[10],val;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        push(arr[i]);
    }
    for(int i=0;i<n;i++){
        val=pop();
        arr[i]=val;
    }
    printf("The reversed array is:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}