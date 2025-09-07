#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top=-1;

void push(char c){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        exit(1);
    }
    else{
        top++;
        stack[top]=c;
    }
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        exit(1);
    }
    else{
        char x=stack[top];
        top--;
        return x;
    }
}

int getPriority(char c){
    if(c=='/'||c=='*'||c=='%'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infixToPostfix(char source[], char target[]){
    int i=0, j=0;
    char temp;
    while(source[i]!='\0'){
        if(source[i]=='('){
            push(source[i]);
            i++;
        }
        else if(source[i]==')'){
            while(top!=-1 && stack[top]!='('){
                target[j]=pop();
                j++;
            }
            if(top==-1){
                printf("INCORRECT EXPRESSION\n");
                exit(1);
            }
            temp=pop(); 
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i])){
            target[j]=source[i];
            j++;
            i++;
        }
        else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%'){
            while(top!=-1 && stack[top]!='(' && getPriority(stack[top])>=getPriority(source[i])){
                target[j]=pop();
                j++;
            }
            push(source[i]);
            i++;
        }
        else{
            printf("INCORRECT EXPRESSION\n");
            exit(1);
        }
    }
    while(top!=-1 && stack[top]!='('){
        target[j]=pop();
        j++;
    }
    target[j]='\0';
}

int main(){
    char infix[100], postfix[100];
    printf("Enter the infix Expression: ");
    gets(infix); 
    infixToPostfix(infix, postfix);
    printf("The postfix expression is : %s\n", postfix);
    return 0;
}
