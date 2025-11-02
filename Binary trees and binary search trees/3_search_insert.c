#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int value){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node *insert(struct node *root,int value){
    if(root==NULL){
        root=createnode(value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }
    else{
        root->left=insert(root->left,value);
    }
}
struct node *search(struct node *root,int key){
    if(root==NULL||root->data==key){
        return root;
    }
    if(key>root->data){
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}
struct node *smallestElement(struct node *root){
    if(root==NULL||root->left==NULL){
        return root;
    }
    else{
        return smallestElement(root->left);
    }
}
struct node *largestElement(struct node *root){
    if(root==NULL||root->right==NULL){
        return root;
    }
    else{
        return largestElement(root->right);
    }
}
int main(){
    struct node *root=createnode(25);
    insert(root,12);
    insert(root,27);
    insert(root,6);
    insert(root,14);
    insert(root,26);
    insert(root,32);
    insert(root,4);
    insert(root,8);
    int ch, key;
    int k;
    struct node *res = NULL; 
    printf("MENU:\n1.Search\n2.Insert\n3.Find smallest element\n4.Find largest element\n");
    while(1){
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: 
                    printf("Enter the element to be searched:\n");
                    scanf("%d",&key);
                    struct node *result=search(root,key);
                    if(result!=NULL){
                        printf("%d is found\n",result->data);
                    }
                    else{
                        printf("%d is not found\n",key);
                    }
                    break;
            case 2:
                    printf("Enter the elememt to be inserted:\n");
                    scanf("%d",&k);
                    insert(root,k);
                    printf("%d is inserted\n");
                    break;
            case 3:
                    result=smallestElement(root);
                    printf("%d is smallest element\n",result->data);
                    break;
            case 4:
                    result=largestElement(root);
                    printf("%d is largest element\n",result->data);
                    break;
            default:
                    printf("Invalid Choice\n");
        }
    }
}