//using another function
#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node* insert_at_beg(struct node *Head,int *Choice)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    if(Head==NULL)
    {
        Head=newnode;
        newnode->link=NULL;
    }
    else
    {
        newnode->link=Head;
        Head=newnode;
    }
    printf("Do you want to add a new element again at the beginning? Press 1:");
    scanf("%d",Choice);
    return Head;
}
int main()
{
    int num;
    struct node *head=NULL,*temp,*newnode;
    printf("How many elements do you want to enter?");
    scanf("%d",&num);
    if (num<1)
    printf("You choose to enter nothing\n");
    else
    {
        head=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&head->data);
        temp=head;
        temp->link=NULL;

        for (int i=2; i<=num; i++)
        {
            newnode=malloc(sizeof (struct node));
            printf("Enter data:");
            scanf("%d",&newnode->data);
            temp->link=newnode;
            newnode->link=NULL;
            temp=newnode;
        }
        printf("Elements entered successfully!\n");
    }
    int choice=0;
    printf("Do you want to enter an element at the beginning of the list? Press 1:");
    scanf("%d",&choice);
    while(choice==1)
    head=insert_at_beg(head,&choice);

    temp=head;
    printf("The final list is:\n");
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    return 0;
}