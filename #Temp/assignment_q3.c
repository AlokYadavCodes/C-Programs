#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};

void insert(struct node **head,int data)
{
    struct node *newnode=malloc(sizeof (struct node)),*temp;
    newnode->data=data;
    newnode->link=NULL;
    if (*head==NULL)
    {
        *head=temp=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=temp->link;
    }
}

void print(struct node *head)
{
    if (head==NULL)
    {
        printf("The list is empty\n");
        return ;
    }
    struct node *temp=head;
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

struct node* combine(struct node *h1,struct node *h2)
{
    struct node *temp1=h1,*temp2=h2;
    struct node *head=NULL;
    while(temp1!=NULL && temp2!=NULL)
    {
        insert(&head,temp1->data);
        insert(&head,temp2->data);
        temp1=temp1->link;
        temp2=temp2->link;
    }
    while(temp1!=NULL)
    {
        insert(&head,temp1->data);
        temp1=temp1->link;
    }
    while(temp2!=NULL)
    {
        insert(&head,temp2->data);
        temp2=temp2->link;
    }
    return head;
}

int main()
{
    struct node *A=NULL,*B=NULL;
    insert(&A,7);
    insert(&A,5);
    insert(&A,3);
    insert(&A,1);
    insert(&A,20);
    insert(&B,6);
    insert(&B,25);
    insert(&B,32);
    insert(&B,11);
    insert(&B,9);
    
    struct node *C=NULL;
    C=combine(A,B);
    print(C);

    return 0;
}