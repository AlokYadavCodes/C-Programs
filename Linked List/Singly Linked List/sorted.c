#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};

void insert(struct node **head,int data)
{
    struct node *newnode=malloc(sizeof(struct node)),*temp;
    newnode->data=data;
 
    if(*head==NULL || newnode->data<=(*head)->data)
    {
        newnode->link=*head;
        *head=newnode;
        return;
    }
    temp=*head;
    while(temp->link!=NULL && temp->link->data<newnode->data)
    {
        temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;
    return;  
}

void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int main()
{
    struct node *head=NULL;
    insert(&head,23);
    insert(&head,12);
    insert(&head,32);
    insert(&head,11);
    insert(&head,45);
    insert(&head,39);
    insert(&head,99);
    insert(&head,18);
    insert(&head,20);
    printf("Here's the output:\n");
    print(head);
}