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
int main(){
    struct node *root=createnode(10);
    root->left=createnode(20);
    root->right=createnode(30);
    root->left->left=createnode(40);
    root->left->right=createnode(50);
    root->right->left=createnode(60);
    root->left->left->left=createnode(70);
    root->left->left->right=createnode(80);
    root->left->right->right=createnode(90);
    printf("PRE-ORDER(root,left,right):  ");
    preOrder(root);
    printf("\n");
    printf("IN-ORDER(left,root,right):  ");
    inOrder(root);
    printf("\n");
    printf("POST-ORDER(left,right,root):  ");
    postOrder(root);
    printf("\n");
}