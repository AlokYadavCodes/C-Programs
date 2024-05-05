#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};


void insert (struct node **head,int data)
{
    struct node *temp;
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=temp=newnode;
        newnode->prev=NULL;
    }
    else
    {
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;
    }
}


void print(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

void reverse(struct node **head)
{
    struct node *temp=*head,*temp2=(*head)->next;

    while(temp2!=NULL)
    {
        temp->next=temp->prev;
        temp->prev=temp2;
        temp=temp2;
        temp2=temp2->next;
    }
    *head=temp;
    temp->next=temp->prev;
    temp->prev=temp2;
}

int main()
{
    struct node *head=NULL;
    insert(&head,11);
    insert(&head,33);
    insert(&head,22);
    insert(&head,44);
    insert(&head,55);
    print(head);
    reverse(&head);
    print(head);

    return 0;
}