#include<stdio.h>
#include<ctype.h>
#define MAXSTACK 100
#define POST 100
int stack[MAXSTACK];
int top=-1;
void push(int item){
	if(top>=MAXSTACK-1){
		printf("Stack is Overflow\n");
		return;
	}
	else{
		top=top+1;
		stack[top]=item;
	}
}
int pop(){
	int item;
	if(top<0){
		printf("Stack Underflow");
	}
	else{
		item=stack[top];
		top=top-1;
		return item;
	}
}
void EvalPostFix(char postfix[]){
	int i,val,A,B;
	char ch;
	for(i=0;postfix[i]!=')';i++){
		ch=postfix[i];
		if(isdigit(ch)){
			push(ch-'0');
		}
		else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
			A=pop();
			B=pop();
			switch(ch){
				case '*':
					val=B*A;
					break;
				case '/':
					val=B/A;
					break;
				case '+':
					val=B+A;
					break;
				case '-':
					val=B-A;
					break;
			}
			push(val);
		}
		
	}
	printf("Result = %d\n",pop());                                            
}
int main(){
	int i;
	char postfix[POST];
	printf("\nEnter postfix expression(press right parenthesis')' for end expression):\n");
	for(i=0;i<=POST-1;i++){
		scanf("%c",&postfix[i]);
		if(postfix[i]==')'){
			break;
		}
	}
	EvalPostFix(postfix);
	return 0;
}