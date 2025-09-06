#include<stdio.h>
struct student{
    int rollno;
    char name[20];
    char dob[20];
};
int main(){
    struct student *ptr,s1;
    ptr=&s1;
    printf("Enter the roll number: ");
    scanf("%d",&ptr->rollno);
    printf("Enter the name: ");
    scanf("%s",ptr->name);
    printf("Enter date of birth: ");
    scanf("%s",ptr->dob);
    printf("\nThe Student details are:\n");
    printf("Roll no: %d",ptr->rollno);
    printf("\nName: %s",ptr->name);
    printf("\nDOB: %s",ptr->dob);
}