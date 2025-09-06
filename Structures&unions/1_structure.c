#include<stdio.h>
struct student{
    int rollno;
    char name[20];
    char dob[20];
};
struct student s1;
int main(){
    printf("Enter the roll number: ");
    scanf("%d",&s1.rollno);
    printf("Enter the name: ");
    scanf("%s",s1.name);
    printf("Enter date of birth: ");
    scanf("%s",s1.dob);
    printf("\nThe Student details are:\n");
    printf("Roll no: %d",s1.rollno);
    printf("\nName: %s",s1.name);
    printf("\nDOB: %s",s1.dob);
}