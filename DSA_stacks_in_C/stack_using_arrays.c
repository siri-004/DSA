#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;

void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=x;
        printf("%d is pushed into the stack\n",x);
    }
}

void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is popped from the stack\n",stack[top]);
        top--;
    }
}

void display(){
    if(top==-1){\
        printf("Stack is empty\n");
    }
    else{
        printf("The elements are: \n");
        for(int i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Peek element of stack is: %d\n",stack[top]);
    }
}

int main(){
    int ch,val;
    printf("MENU:\n1.Push\n2.Pop\n3.Display\n4.Peek\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the value to be pushed: ");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
