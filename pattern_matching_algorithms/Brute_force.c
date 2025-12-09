#include<stdio.h>
#include<string.h>
int BruteForce(char T[],char P[]){
    int n=strlen(T);
    int m=strlen(P);
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m&&T[i+j]==P[j]){
            j++;
        }
        if(j==m){
            return i;
        }
    }
    return -1;
}
int main(){
    char text[100],pattern[100];
    printf("Enter text: ");
    scanf("%s",&text);
    printf("Enter pattern: ");
    scanf("%s",&pattern);
    int pos=BruteForce(text,pattern);
    if(pos==-1){
        printf("Pattern not found\n");
    }
    else{
        printf("Pattern found at position %d\n",pos+1);
    }
    return 0;
}