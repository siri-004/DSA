#include<stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue is Overflow\n");
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}
void dequeue(){
    if((front==-1&&rear==-1)||(front>rear)){
        printf("Queue is Underflow\n");
    }
    else if(front==rear){
        printf("%d is dequeued from queue\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("%d id dequeued from queue\n",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("The Queue elements are : \n");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Peek element is %d \n",queue[front]);
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
