#include<stdio.h>
#define MAX 10
int cq[MAX];
int front=-1,rear=-1;
void enqueue(int x){
    if(front==(rear+1)%MAX){
        printf("Circular Queue is Overflow\n");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        cq[rear]=x;
    }
    else{
        rear=(rear+1)%MAX;
        cq[rear]=x;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Circular Queue is Underflow\n");
    }
    else if(front==rear){
        printf("%d is dequeued from Circular Queue\n",cq[front]);
        front=rear=-1;
    }
    else{
        printf("%d is dequeued from Circular Queue\n",cq[front]);
        front=(front+1)%MAX;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Circular Queue is empty\n");
    }
    else{
        int i=front;
        do{
            printf("%d ",cq[i]);
            i=(i+1)%MAX;
        }while(i!=(rear+1)%MAX);
        printf("\n");
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("Circular Queue is empty\n");
    }
    else{
        printf("Peek element is %d \n",cq[rear]);
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