#include<stdio.h>
#include<stdlib.h>
struct student{
    int rollno;
    char name[20];
    int marks;
};
void display(struct student *s){
    printf("Roll no: %d\n",s->rollno);
    printf("Name: %s\n",s->name);
    printf("Marks: %d\n",s->marks);
    printf("\n");
}
int main(){
    struct student *ptr;
    ptr=(struct student *)malloc(sizeof(struct student));
    printf("Enter the roll number: ");
    scanf("%d",&ptr->rollno);
    printf("Enter the name: ");
    scanf("%s",ptr->name);
    printf("Enter total marks: ");
    scanf("%d",&ptr->marks);
    display(ptr);
    }