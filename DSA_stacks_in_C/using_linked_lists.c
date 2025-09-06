#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL,*temp;
void push(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top; 
    top=newnode;
    }
void pop(){
    temp=top;
    if(top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is popped from stack\n",temp->data);
        top=top->next;
        free(temp);
    }
}
void display(){
    temp=top;
    if(temp==NULL){
        printf("Stack is empty\n");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

}
void peek(){
    if(top==NULL){
        printf("Stack Underflow\n");
    }
    else{
        printf("%d is top of the stack\n",top->data);
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
