#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL,*temp,*newnode;
void create(){
    int x,ch=1;
	while(ch==1){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&x);
		newnode->data=x;
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
            newnode->next=head;
		}
		else{
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
			temp->next=newnode;
			newnode->next=head;
		}
		printf("Enter your choice:(1 to continue to create a node)");
		scanf("%d",&ch);
		
	}
}
void display(){
    if (head==NULL){
        printf("Cirular linked list is empty\n");
        return;
    }
    temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
void insertAtFirst(){
    int x;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&x);
        newnode->data=x;
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        
}
void insertAtLast(){
    int x;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&x);
        newnode->data=x;
        temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
}
void count(){
    if(head==NULL){
		printf("Cirular linked list is empty\n");
	}
	else{
		int c=0;
        temp=head;
        do{
            temp=temp->next;
			c++;
        }while(temp!=head);
	    printf("Number of nodes is %d\n",c);
	}
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
        free(head);
        head = NULL;
        return;
    }
    while(last->next!=head){
            last=last->next;
        }
    head=head->next;
    last->next=head;
    free(temp);
}
void deleteAtLast(){
    if(head==NULL){
			printf("Cirular linked list is empty\n");
		}
    else if(head->next==head){
        free(head);
        head = NULL;
    }
	else{
		temp=head;
		struct node *pre;
		while(temp->next!=head){
			pre=temp;
			temp=temp->next;
		}
		pre->next=head;
		free(temp);
	}
}
void delete_list(){
    if(head==NULL){
        printf("Cirular linked list is empty\n");
        return;
    }
    while(head!=NULL){   
        deleteAtFirst();
    }
    printf("Entire List deleted\n");
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
void insertAtPosition(){
    int pos,i;
    printf("Enter the position where node has to be inserted: ");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        if(pos==1){
            head=newnode;
            newnode->next=head;
        }
        else{
            printf("Invalid position\n");
            free(newnode);
        }
        return;
    }
    if(pos==1){
        insertAtFirst();
        return;
    }
    temp=head;
    for(i=1;i<pos-1 && temp->next!=head;i++){
        temp=temp->next;
    }
    if(temp->next==head && i<pos-1){
        printf("Invalid position\n");
        free(newnode);
    }
    else{
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void deleteAtPosition(){
    int pos,i;
    printf("Enter the position where node has to be deleted: ");
    scanf("%d",&pos);
    if(head==NULL){
        printf("List empty\n");
        return;
    }
    if(pos==1){
        deleteAtFirst();
        return;
    }
    temp=head;
    struct node *curr;
    for(i=1;i<pos && temp->next!=head;i++){
        curr=temp;
        temp=temp->next;
    }
    if(temp->next==head && i<pos){
        printf("Invalid position\n");
    }
    else{
        curr->next=temp->next;
        free(temp);
    }
}
int main()
{
	int ch;
	printf("MENU:\n1.Create\n2.Display\n3.Insert At First\n4.Insert At Last\n5.Count number of nodes\n");
    printf("6.Delete At First\n7.Delete At Last\n8.Delete list\n9.Sort list\n");
    printf("10.Insert At Position\n11.Delete At Position\n");
	while(1){
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1 :create();
					 break;
			case 2 :display();
					 break;	
			case 3 :insertAtFirst();
					 break;		 
			case 4 :insertAtLast();
					 break;	
			case 5 :count();
					break;
			case 6 :deleteAtFirst();
				   break;
            case 7 :deleteAtLast();
                   break;
			case 8: delete_list();
					break;
			case 9: sort_list();
					break;
            case 10: insertAtPosition();
                    break;
            case 11: deleteAtPosition();
                    break;
			default: printf("Invalid choice");
		}
	}
	return 0;
}