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
void preOrder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct node *root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct node *root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
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
int countNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    int leftNodes=countNodes(root->left);
    int rightNodes=countNodes(root->right);
    return leftNodes+rightNodes+1;
}
int sumOfNodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumOfNodes(root->left);
    int rightSum=sumOfNodes(root->right);
    return leftSum+rightSum+root->data;
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
    printf("PRE-ORDER(root,left,right):  ");
    preOrder(root);
    printf("\n");
    printf("IN-ORDER(left,root,right):  ");
    inOrder(root);
    printf("\n");
    printf("POST-ORDER(left,right,root):  ");
    postOrder(root);
    printf("\n");
    printf("Number of nodes is : %d\n",countNodes(root));
    printf("Sum of nodes is : %d",sumOfNodes(root));
}