#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head;
void insert_at_beg()
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->link=head;
    head=newnode;
}
int main()
{
    int i=0,j=0;
    printf("How many elements do you want to enter:");
    scanf("%d",&i);
    struct node *temp,*newnode;
    if (i>=1)
    {
        newnode=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        head=temp=newnode;
        newnode->link=NULL;
    }
    for (int j=2;j<=i;j++)
    {
        newnode=malloc (sizeof(struct node));
        temp->link=newnode;
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        temp=newnode;
    }
    printf("Elements entered successfully!\n");
    printf("Here's what you have entered: \n");
    struct node *current=head;
    for(int j=0;j<i;j++)
    {
        printf("%d\n",current->data);
        current=current->link;
    }
    int pos,count=0;
    printf("Enter the position where you want to enter a new element in the list:");
    scanf("%d",&pos);
    current=head;
    while(current!=NULL)
    {
        current=current->link;
        count++;
    }
    //printf("Count = %d",count);
    if(pos>count+1 || pos<1)
    printf("Invalid Position");
    else
    {
        if(pos==1) insert_at_beg();
    else
    {
        current=head;
        for (int j=1;j<pos-1;j++)
        {
            current=current->link;
        }
        newnode=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->link=current->link;
        current->link=newnode;
    }
        printf("Element inserted successfully! Have a look at updated list:\n");
        current=head;
        for(int j=0;j<=i;j++)
        {
        printf("%d\n",current->data);
        current=current->link;
        }
        free(current);
        printf("Program Ended :)\n");
    }
    
    return 0; 
}