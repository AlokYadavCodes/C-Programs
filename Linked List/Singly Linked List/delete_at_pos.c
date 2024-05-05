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

int length (struct node *head)
{
    struct node *temp=head;
    int len=0;
    while (temp->link!=NULL)
    {
        len++;
        temp=temp->link;
    }
return len;
}

void delete(struct node **head,int pos)
{
    int len=length(*head);
    if (pos<1 || pos>len)
    {
        printf("Invalid Position\n");
        return;
    }

    if (pos==1)
    {
        struct node *temp=*head;
        *head=(*head)->link;
        free(temp);
    }
    else
    {
        struct node *current=*head,*prev=NULL;
        while (pos!=1)
        {
            prev=current;
            current=current->link;
            pos--;
        }
        prev->link=current->link;
        free(current);
        current=NULL;
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
    printf("Enter the position to be deleted:");
    int pos;
    scanf("%d",&pos);
    delete(&head,pos);
    printf("After deletion:\n");
    print(head);
    return 0;

}