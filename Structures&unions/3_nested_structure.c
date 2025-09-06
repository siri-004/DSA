#include<stdio.h>
struct DOB{
    int day;
    int month;
    int year;
};
struct student{
    int rollno;
    char name[20];
    struct DOB date;
};
struct student s1;
int main(){
    printf("Enter the roll number: ");
    scanf("%d",&s1.rollno);
    printf("Enter the name: ");
    scanf("%s",s1.name);
    printf("Enter date of birth: ");
    scanf("%d %d %d",&s1.date.day,&s1.date.month,&s1.date.year);
    printf("\nThe Student details are:\n");
    printf("Roll no: %d",s1.rollno);
    printf("\nName: %s",s1.name);
    printf("\nDOB: %d-%d-%d",s1.date.day,s1.date.month,s1.date.year);
}