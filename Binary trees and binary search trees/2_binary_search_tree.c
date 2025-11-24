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
struct node *minimum(struct node *nn){
    struct node *current=nn;
    while(current&&current->left!=NULL){
        current=current->left;
    }
    return current;
}
struct node *deleteNode(struct node *root,int element){
    if(root==NULL){
        return root;
    }
    else if(element<root->data){
        root->left=deleteNode(root->left,element);
    }
    else if(element>root->data){
        root->right=deleteNode(root->right,element);
    }
    else if(root->left==NULL&&root->right==NULL){
        free(root);
        root=NULL;
        return root;
    }
    else if(root->left==NULL){
        struct node *temp=root;
        root=root->right;
        free(temp);
        return root;
    }
    else if(root->right==NULL){
        struct node *temp=root;
        root=root->left;
        free(temp);
        return root;
    }
    else{
        struct node *temp=minimum(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
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
int height(struct node *root){
    if(root==NULL){
        return 0;
    }
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    int myheight=(leftheight>rightheight) ? leftheight: rightheight;
    return myheight+1;
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
    printf("Sum of nodes is : %d\n",sumOfNodes(root));
    printf("Height of the tree : %d\n",height(root));
    root=deleteNode(root,26);
    printf("%d is deleted\n",26);
    printf("IN-ORDER(left,root,right):  ");
    inOrder(root);
    printf("\n");
}