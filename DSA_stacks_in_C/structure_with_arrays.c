#include<stdio.h>
#define MAX 5

struct Stack{
    int arr[MAX];
    int top;
};
void init(struct Stack *s){
    s->top=-1;
}
void push(struct Stack *s,int value){
    if(s->top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=value;
    }
}
void pop(struct Stack *s){
    if(s->top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is popped from the stack\n",s->arr[s->top]);
        s->top--;
    }
}
void display(struct Stack *s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("The elements are: \n");
        for(int i=s->top;i>=0;i--){
            printf("%d ",s->arr[i]);
        }
        printf("\n");
    }
}
void peek(struct Stack *s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("Peek element of stack is: %d\n",s->arr[s->top]);
    }
}

int main(){
    struct Stack s;
    int ch,val;
    init(&s);
    printf("MENU:\n1.Push\n2.Pop\n3.Display\n4.Peek\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the value to be pushed: ");
                    scanf("%d",&val);
                    push(&s,val);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(&s);
                    break;
            case 4: peek(&s);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}