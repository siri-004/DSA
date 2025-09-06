#include<stdio.h>
#include<stdlib.h>
struct student{
    int rollno;
    char name[20];
    int marks;
};
struct student *ptr[10];
int main(){
    int n;
    printf("Enter number of Students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ptr[i]=(struct student *)malloc(sizeof(struct student));
        printf("Enter the roll number: ");
        scanf("%d",&ptr[i]->rollno);
        printf("Enter the name: ");
        scanf("%s",ptr[i]->name);
        printf("Enter total marks: ");
        scanf("%d",&ptr[i]->marks);
    }
    printf("\nThe Student details are:\n");
    for(int i=0;i<n;i++){
        printf("Roll no: %d\n",ptr[i]->rollno);
        printf("Name: %s\n",ptr[i]->name);
        printf("Marks: %d\n",ptr[i]->marks);
        printf("\n");
    }
}
