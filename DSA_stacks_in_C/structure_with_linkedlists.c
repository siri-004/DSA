#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *temp;
struct Stack{
    struct Node *top;
};
void init(struct Stack *s){
    s->top=NULL;
}
void push(struct Stack *s,int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=s->top;
    s->top=newnode;
}
void pop(struct Stack *s){
    temp=s->top;
    if(s->top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        temp=s->top;
        printf("%d is popped from stack\n",temp->data);
        free(temp);
        s->top=temp->next;
    }
}
void display(struct Stack *s) {
    struct node *temp=s->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void peek(struct Stack *s){
    
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