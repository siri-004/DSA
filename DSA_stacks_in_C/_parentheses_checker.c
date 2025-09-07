#include<stdio.h>
#include<string.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(char c){
    if(top==(MAX-1)){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=c;
    }
}
char pop(){
    if(top==-1){
        printf("Stack Undeflow\n");
    }
    else{
        char x=stack[top];
        top--;
        return x;
    }
}
int main(){
    char ex[MAX],temp;
    int flag=1;
    printf("Enter an expression: ");
    scanf("%s",ex);
    for(int i=0;i<strlen(ex);i++){
        if(ex[i]=='('||ex[i]=='{'||ex[i]=='['){
            push(ex[i]);
        }
        if(ex[i]==')'||ex[i]=='}'||ex[i]==']'){
            if(top==-1){
                flag=0;
            }
            else{
                temp=pop();
                if(ex[i]==')'&&(temp=='{'||temp=='[')){
                    flag=0;
                }
                if(ex[i]=='}'&&(temp=='('||temp=='[')){
                    flag=0;
                }
                if(ex[i]==']'&&(temp=='('||temp=='{')){
                    flag=0;
                }
            }
        }
    }
    if(top>=0){
        flag=0;
    }
    if(flag==1){
        printf("Valid Expression\n");
    }
    else{
        printf("Invalid Expression\n");
    }
}