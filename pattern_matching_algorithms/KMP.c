#include<stdio.h>
#include<string.h>
void failurefunction(char P[],int F[]){
    int m=strlen(P);
    F[0]=0;
    int i=1,j=0;
    while(i<m){
        if(P[i]==P[j]){
            F[i]=j+1;
            i++;
            j++;
        }
        else if(j>0){
            j=F[j-1];
        }
        else{
            F[i]=0;
            i++;
        }
    }
}
int KMP(char T[],char P[]){
    int n=strlen(T);
    int m=strlen(P);
    int F[m];
    failurefunction(P,F);
    int i=0,j=1;
    while(i<n){
        if(T[i]==P[j]){
            if(j==m-1){
                return i-j;
            }
            else{
                i++;
                j++;
            }
        }
        else if(j>0){
            j=F[j-1];
        }
        else{
            i++;
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
    int pos=KMP(text,pattern);
    if(pos==-1){
        printf("Pattern not found\n");
    }
    else{
        printf("Pattern found at position %d\n",pos+1);
    }
    return 0;
}