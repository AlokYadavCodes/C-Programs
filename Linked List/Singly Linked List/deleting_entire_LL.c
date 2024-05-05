#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};

void insert(struct node **head,int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    struct node *temp;
    newnode->data=data;
    newnode->link=NULL;
    if(*head==NULL)
    {
        *head=temp=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=newnode;
    }
}

void delete(struct node **head)
{
    struct node *temp;
    while(*head!=NULL)
    {
        temp=*head;
        *head=(*head)->link;
        free(temp);
        temp=NULL;
    }
}


void print(struct node *head)
{
    struct node *temp=head;
    if (temp==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int main ()
{
    struct node *head=NULL;
    insert(&head,3);
    insert(&head,7);
    insert(&head,10);
    insert(&head,15);
    insert(&head,16);
    insert(&head,9);
    insert(&head,22);
    print(head);
    delete(&head);
    printf("After deleting:\n");
    print(head);
    
    return 0;

}