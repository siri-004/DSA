#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
};
struct node *head=NULL,*temp,*newnode;
void create(){
	int ch=1;
	while(ch==1){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL){
			head=temp=newnode;
			head->next=newnode;
			head->prev=newnode;
		}
		else{
			temp=head;
			while(temp->next!=head){
				temp=temp->next;
			}
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=head;
			head->prev=newnode;
		}
		printf("Press 1 to continue to create nodes:");
		scanf("%d",&ch);
	}
}
void display(){
	temp=head;
	if(head==NULL){
		printf("Linked list is empty\n");
	}
	else{
		do{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=head);
	}
	printf("\n");
}
void deleteAtFirst(){
    struct node *last;
    temp=head;
    last=head;
    if(head == NULL){
        printf("Circular linked list is empty\n");
        return;
    }
    if(head->next == head){
        printf("%d is deleted\n",head->data);
        free(head);
        head = NULL;
        return;
    }
    while(last->next!=head){
            last=last->next;
        }
    head=head->next;
    last->next=head;
    head->prev=last;
    printf("%d is deleted\n",temp->data);
    free(temp);
}
void deleteAtLast(){
    if(head==NULL){
            printf("Cirular linked list is empty\n");
        }
    else if(head->next==head){
        printf("%d is deleted\n",head->data);
        free(head);
        head = NULL;
        return;
    }
    else{
        temp=head;
        struct node *pre=head;
        while(temp->next!=head){
            pre=temp;
            temp=temp->next;
        }
        pre->next=head;
        head->prev=pre;
        printf("%d is deleted\n",temp->data);
        free(temp);
    }
}
void sort_list() {
    struct node *p1, *p2;
    int temp;

    if (head == NULL || head->next == head) {
        return;
    }
    p1 = head;
    do {
        p2 = p1->next;
        while (p2 != head) {
            if (p1->data > p2->data) {
                temp = p1->data;
                p1->data = p2->data;
                p2->data = temp;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    } while (p1->next != head);
}
void count(){
    if(head==NULL){
        printf("Circular linked list is empty\n");
    }
    else{
        int c=0;
        temp=head;
        do{
            temp=temp->next;
            c++;
        }while(temp!=head);
        printf("Number of nodes: %d\n",c);
    }
}
void insertAtFirst(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at first: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        struct node *last = head->prev;
        newnode->next = head;
        newnode->prev = last;
        last->next = newnode;
        head->prev = newnode;
        head = newnode;
    }
}
void insertAtLast(){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data to insert at last: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
        head->next=head;
        head->prev=head;
    }
    else{
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=head;
        head->prev=newnode;
    }
}
void insertAtPosition(){
	int pos,i;
    printf("Enter the position where node should be inserted :");
	scanf("%d",&pos);
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
    if(pos==1){
        insertAtFirst();
        return;
    }

	temp=head;
	for(i=0;i<pos-1;i++){
		temp=temp->next;
	}
	temp->next->prev=newnode;
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->prev=temp;;
}
void deleteAtPosition(){
	struct node *curr;
	temp=curr=head;
	int pos,i;
	printf( "Enter the position where node should be deleted:");
	scanf("%d",&pos);
    if(pos == 1){ 
        deleteAtFirst();
        return;
    }
	for(i=0;i<pos;i++){
		temp=temp->next;
		curr=temp->next;
	}
	temp->next=temp->next->next;
	temp->next->prev=temp;
    printf("%d is deleted\n",curr->data);
	free(curr);	
}
int main(){
	int choice;
	printf("Menu:\n1.Create\n2.Display\n3.Insert At Position\n4.Delete At Position\n");
    printf("5.Insert At First\n6.Insert At Last\n7.Delete At First\n8.Delete At Last\n9.Count Nodes\n10.Sort List\n");
	while(1){
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1 : create();
					 break;
			case 2 : display();
					 break;
			case 3 : insertAtPosition();
					 break;
			case 4 : deleteAtPosition();
					 break;
            case 5 : insertAtFirst();
                     break;
            case 6 : insertAtLast();
                     break;
            case 7 : deleteAtFirst();
                     break;
            case 8 : deleteAtLast();
                     break;
            case 9 : count();
                     break;
            case 10: sort_list();
                     break;
			default : printf("Invalid choice");
		}
	}
	return 0;
}