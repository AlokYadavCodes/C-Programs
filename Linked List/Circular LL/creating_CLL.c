//singly linked list    using head

#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
void create(struct node **head)
{
    printf("Enter the number of elements in the List:");
    int n;
    scanf("%d",&n);
    if (n<1)
    {
        printf("Entered value is less than 1\n Please try again\n");
        return;
    }
    for (int i=0;i<n;i++)
    {
        struct node *newnode=malloc(sizeof (struct node)),*temp;
        printf("Enter data:");
        scanf("%d",&newnode->data);
        if(*head==NULL)
        {
            *head=temp=newnode;
            newnode->link=*head;
        }
        else
        {
            temp->link=newnode;
            newnode->link=*head;
            temp=newnode;
        }
    }
}

void print(struct node *head)
{
    struct node *temp=head;
    do
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    } while(temp!=head);

}    


int main()
{
    struct node *head=NULL;
    create(&head);
    print(head);

}
