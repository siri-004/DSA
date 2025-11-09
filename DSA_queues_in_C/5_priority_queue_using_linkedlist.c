#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node *next;
};
struct node *createnode(int d,int p){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->priority=p;
    newnode->next=NULL;
    return newnode;
}
struct node *insert(struct node *head,int d,int p){
    struct node *start=head;
    struct node*temp=createnode(d,p);
    if(head==NULL||head->priority<p){
        temp->next=head;
        head=temp;
    }
    else{
        while(start->next!=NULL&&start->next->priority>=p){
            start=start->next;
        }
        temp->next=start->next;
        start->next=temp;
    }
    return head;
}
void display(struct node *head){
    struct node *temp=head;
    printf("Priortiy Queue: ");
    while(temp!=NULL){
        printf("[%d p=%d] ",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}
struct node *delete(struct node *head){
    if(head==NULL){
        printf("Priority Queue is empty\n");
        return NULL;
    }
    struct node* temp = head;
    printf("Deleted element: %d (priority %d)\n", temp->data, temp->priority);
    head = head->next;
    free(temp);
    return head; 
}
int main(){
    struct node *pq=NULL;
    int ch,d,p;
    printf("MENU:\n1.Insert\n2.Display\n3.Delete\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the data with its priority: ");
                    scanf("%d %d",&d,&p);
                    pq=insert(pq,d,p);
                    break;
            case 2: display(pq);
                    break;
            case 3: pq=delete(pq);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}