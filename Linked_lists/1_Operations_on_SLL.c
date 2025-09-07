#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL,*temp,*newnode;
int i;
void create(){
	int x,ch=1;
	while(ch==1){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&x);
		newnode->data=x;
		newnode->next=NULL;
		if(head==NULL){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("Enter your choice:(1 to continue to create a node)");
		scanf("%d",&ch);
		
	}
}
void display(){
	if(head==NULL){
		printf("Linked list is empty\n");
	}
	else{
		temp=head;
		while(temp!=NULL){
  						  printf("%d ",temp->data);
						  temp=temp->next;
	 }
 	 printf("\n");
	}
}
void insertAtFirst(){
	    int x;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&x);
		newnode->data=x;
		newnode->next=NULL;
		newnode->next=head;
		head=newnode;
}
void insertAtLast(){
	    int x;
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data:");
		scanf("%d",&x);
		newnode->data=x;
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
		temp->next=newnode;
	}
}
void insertAtPosition(){
	int pos,x;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter the position where node should be inserted: ");
	scanf("%d",&pos);
	if(pos==0)
	{
		insertAtFirst();
	}
	else{
		printf("Enter data:");
		scanf("%d",&x);
		newnode->data=x;
		newnode->next=NULL;
		temp=head;
		struct node *pre;
		for(i=0;i<pos;i++){
			pre=temp;
			temp=temp->next;
		}
		pre->next=newnode;
		pre=newnode;
		pre->next=temp;
	}
}
void insert_before(){
	int x,val;
	printf("Enter the value before which node has to be inserted: ");
	scanf("%d",&x);
	printf("Enter data: ");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	temp=head;
	struct node *pre;
	while(temp->data!=x){
		pre=temp;
		temp=temp->next;
	}
	pre->next=newnode;
	pre=newnode;
	pre->next=temp;
}
void insert_after(){
	int x,val;
	printf("Enter the value after which node has to be inserted: ");
	scanf("%d",&x);
	printf("Enter data: ");
	scanf("%d",&val);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=NULL;
	temp=head;
	struct node *pre;
	pre=temp;
	while(pre->data!=x){
		pre=temp;
		temp=temp->next;
	}
	pre->next=newnode;
	pre=newnode;
	pre->next=temp;
}
void deleteAtFirst(){
	temp=head;
	head=head->next;
	free(temp);
}
void deleteAtPosition(){
	int pos;
	printf("Enter the position where node should be deleted: ");
	scanf("%d",&pos);
	if(pos==0){
		deleteAtFirst();
	}
	else{
		temp=head;
		struct node *pre,*forward;
		for(i=0;i<pos;i++){
			pre=temp;
			temp=temp->next;
			forward=temp->next;
		}
		pre->next=forward;
		free(temp);
	}
}

void deleteAtLast(){
	if(head==NULL){
			printf("Linked list is empty\n");
		}
		else{
			temp=head;
			struct node *pre;
			while(temp->next!=NULL){
				pre=temp;
				temp=temp->next;
			}
			pre->next=NULL;
			free(temp);
		}
}
void delete_list(){
	if(head!=NULL){
		temp=head;
		while(temp!=NULL){
			deleteAtFirst();
			temp=head;
		}
	}
}
void count(){
	if(head==NULL){
		printf("Linked list is empty\n");
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
void sort_list(){
	struct node *p1,*p2;
	int temp;
	p1=head;
	while(p1->next!=NULL){
		p2=p1->next;
		while(p2!=NULL){
			if(p1->data>p2->data){
				temp=p1->data;
				p1->data=p2->data;
				p2->data=temp;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}

}
int main()
{
	int ch;
	printf("MENU:\n1.Create\n2.Display\n3.Insert At First\n4.Insert At Last\n5.Count number of nodes\n6.Delete At First\n7.Delete At Last\n8.Insert At Position\n9.Delete At Position\n10.Insert before\n11.Insert After\n12.Delete list\n13.Sort list\n");
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
            case 8: insertAtPosition();
            		break;
            case 9: deleteAtPosition();
            		break;
			case 10: insert_before();
					break;
			case 11: insert_after();
					break;
			case 12: delete_list();
					break;
			case 13: sort_list();
					break;
			default: printf("Invalid choice");
		}
	}
	return 0;
}