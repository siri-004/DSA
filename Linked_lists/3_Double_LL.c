#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
};
struct node *newnode,*temp,*head=NULL;
void create(){
	int ch=1;
	while(ch==1){
		newnode=(struct node *)malloc(sizeof(struct node ));
		printf("Enter the data: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		printf("Press 1 to continue to create node: ");
		scanf("%d",&ch);
	}
}
void displayfront(){
	if(head==NULL){
		printf("Double linked list is empty\n");
	}
	else{
		temp=head;
		do{
			printf("%d ",temp->data);
			temp=temp->next;
		}while(temp!=NULL);
		printf("\n");
	}
}
void displayback(){
	if(head==NULL){
		printf("Double linked list is empty\n");
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		do{
			printf("%d ",temp->data);
			temp=temp->prev;
		}while(temp!=NULL);
		printf("\n");
	}
}
void insertAtFirst(){
	newnode=(struct node *)malloc(sizeof(struct node *));
	printf("Enter the data to insert at first: ");
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void insertAtLast(){
	newnode=(struct node *)malloc(sizeof(struct node *));
	printf("Enter the data to insert at last: ");
	scanf("%d",&newnode->data);
	temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	newnode->prev=temp;
	temp->next=newnode;
	newnode->next=NULL;
}
void deleteFirst(){
    if(head==NULL){
        printf("Double linked list is empty\n");
    }
    else if(head->next==NULL){
        printf("%d is deleted\n",head->data);
        free(head);
        head=NULL;
    }
    else{
        printf("%d is deleted\n",head->data);
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void deleteLast(){
    if(head==NULL){
        printf("Double linked list is empty\n");
    }
    else if(head->next==NULL){
        printf("%d is deleted\n",head->data);
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        printf("%d is deleted\n",temp->data);
        temp->prev->next=NULL;
        free(temp);
    }
}
void insertAtPosition(){
    int pos,i;
    printf("Enter the position where node has to be inserted: ");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    if(pos==1){
        insertAtFirst();
        return;
    }
    temp=head;
    for(i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position\n");
        free(newnode);
    }
    else{
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=newnode;
        }
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
        deleteFirst();
        return;
    }
    temp=head;
    for(i=1;i<pos && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Invalid position\n");
    } else {
        printf("%d is deleted\n",temp->data);
        if(temp->next!=NULL){
            temp->next->prev=temp->prev;
        }
        temp->prev->next=temp->next;
        free(temp);
    }
}
void count(){
	if(head==NULL){
		printf("Double Linked list is empty\n");
	}
	else{
		int c=0;
		temp=head;
		while(temp!=NULL){
			temp=temp->next;
			c++;
	 }
	 printf("Number of nodes is %d\n",c);
	}
}
void displayAlternative(){
	if(head==NULL){
		printf("Linked list is empty\n");
	}
	else{
		temp=head;
		while(temp!=NULL){
			printf("%d ",temp->data);
			if(temp->next!=NULL)
                temp=temp->next->next;
            else
                break;
		}
		printf("\n");
	}
}
void searchForNode(){
	int x,c=0,flag=0;
	printf("Enter the data to be searched: ");
	scanf("%d",&x);
	temp=head;
	while(temp!=NULL){
		if(temp->data==x){
			printf("%d is in %d position\n",x,c);
			flag=1;
			break;
		}
		else{
			temp=temp->next;
			c++;
		}
	}
	if(flag==0){
		printf("Element not found\n");
	}
}
int main(){
	int ch,value;
	printf("MENU:\n1.Create\n2.Displayfront\n3.Displayback\n4.Insert At First\n5.Insert At Last\n");
	printf("6.Delete First\n7.Delete Last\n8.Insert At Position\n9.Delete At Position\n");
    printf("10.Count Nodes\n11.Display Alternative\n12.Search For Node\n");
	while(1){
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				displayfront();
				break;
			case 3:
				displayback();
				break;
			case 4:
				insertAtFirst();
				break;
			case 5:
				insertAtLast();
				break;
			case 6:
				deleteFirst();
				break;
			case 7:
				deleteLast();
				break;
			case 8:
				insertAtPosition();
				break;
			case 9:
				deleteAtPosition();
				break;
            case 10:
                count();
                break;
            case 11:
                displayAlternative();
                break;
            case 12:
                searchForNode();
                break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}
