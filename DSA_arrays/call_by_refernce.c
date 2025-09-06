#include<stdio.h>
void add(int *n){
    *n=*n+10;
    printf("The value of number in the called function is: %d\n",*n);
}
int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("The value of number before calling the function is :%d\n",n);
    add(&n);
    printf("The value of number after calling the function is :%d\n",n);
    return 0;
}