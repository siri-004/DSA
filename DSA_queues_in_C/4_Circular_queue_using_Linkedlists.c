#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL,*temp;
void enqueue(int x){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue(){
    if(front==NULL&&rear==NULL){
        printf("Circular Queue is Underflow\n");
    }
    else if(front==rear){
        printf("%d is dequeued from Circular Queue\n",front->data);
        free(front);
        front=rear=NULL;
    }
    else{
        temp=front;
        printf("%d is dequeued from Circular Queue\n",temp->data);
        front=temp->next;
        rear->next=front;
        free(temp);
    }
}
void display(){
    if(front==NULL&&rear==NULL){
        printf("Circular Queue is empty\n");
    }
    temp=front;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=front);
    printf("\n");
}
void peek(){
    if(front==NULL&&rear==NULL){
        printf("Circular Queue is empty\n");
    }
    else{
        printf("%d ",front->data);
    }
}
int main(){
    int ch,val;
    printf("MENU:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the value to be enqueued: ");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
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
