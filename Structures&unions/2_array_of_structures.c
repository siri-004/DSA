#include<stdio.h>
struct student{
    int rollno;
    char name[20];
    char dob[20];
};
struct student s[10];
int main(){
    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the roll number: ");
        scanf("%d",&s[i].rollno);
        printf("Enter the name: ");
        scanf("%s",s[i].name);
        printf("Enter date of birth: ");
        scanf("%s",s[i].dob);
    }
    printf("\nThe Student details are:\n");
    for(int i=0;i<n;i++){
        printf("Roll no: %d\n",s[i].rollno);
        printf("Name: %s\n",s[i].name);
        printf("DOB: %s\n",s[i].dob);
        printf("\n");
    }
}