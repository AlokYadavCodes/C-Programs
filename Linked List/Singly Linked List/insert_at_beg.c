//without using another function
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    int num;
    struct node *head=NULL,*temp=NULL,*newnode;
    printf("How many elements do you want to enter?");
    scanf("%d",&num);
    if (num<1)
    printf("You choose to enter nothing\n");
    else
    {
        head=malloc(sizeof (struct node));
        printf("Enter data:");
        scanf("%d",&head->data);
        temp=head; 
        temp->link=NULL;

        for (int i=2;i<=num;i++)
        {
            newnode=malloc(sizeof (struct node));
            temp->link=newnode;
            printf("Enter data:");
            scanf("%d",&newnode->data);
            newnode->link=NULL;
            temp=newnode;
        }
        printf("Elements entered successfully!\n");
    }
    int choice=0;
    printf("Do you want to enter an element at the beginning of the list? Press 1:");
    scanf("%d",&choice);
    if (choice==1)
    {
        while(choice==1)
        {
            newnode=malloc(sizeof (struct node));
            printf("Enter data:");
            scanf("%d",&newnode->data);
            if (head==NULL)
                {
                    head=newnode;
                    newnode->link=NULL;
                }   
            else
                {
                    newnode->link=head;
                    head=newnode;
                }   
            
            printf("Do you want to enter again any element at the beginning? Press 1:");
            scanf("%d",&choice);
        }
        printf("The list is updated successfully! Have a look at updated list:\n");
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
    else
    {
        printf("Here's what you have entered:\n");
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
    printf("Program Ended :)");
    return 0;
}