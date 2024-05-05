#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
void insert (struct node **head,int data)
{
    struct node *temp;
    struct node *newnode=malloc (sizeof (struct node));
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
struct node* common(struct node *h1 , struct node *h2)
{
    struct node *temp1=h1,*temp2=h2,*head=NULL;
    for (temp1=h1;temp1!=NULL;temp1=temp1->link)
    {
        for (temp2=h2;temp2!=NULL;temp2=temp2->link)
        {
            if (temp1->data==temp2->data)
            insert(&head,temp1->data);
        }
    }
    return head;

}
void print(struct node *head)
{
    struct node *temp=head;
    if (temp==NULL)
    {
        printf("The list is empty\n");
        return ;
    }
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    
    
}
struct node* combine(struct node *h1,struct node *h2)
{
    struct node *head=NULL;
    struct node *temp1=h1,*temp2=h2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if (temp1->data<temp2->data)
        {
            insert(&head,temp1->data);
            temp1=temp1->link;
        }
        else if (temp1->data>temp2->data)
        {
            insert(&head,temp2->data);
            temp2=temp2->link;
        }
        else
        {
            insert(&head,temp1->data);
            temp1=temp1->link;
            temp2=temp2->link;
        }
    }
    while(temp1!=NULL)
    {
        insert(&head,temp1->data);
        temp1=temp1->link;
    }
    while (temp2!=NULL)
    {
        insert(&head,temp2->data);
        temp2=temp2->link;
    }
    return head;
    
}

int main()
{
    struct node *A=NULL,*B=NULL,*C=NULL,*D=NULL;
    insert(&A,3);
    insert(&A,7);
    insert(&A,10);
    insert(&A,15);
    insert(&A,16);
    insert(&A,9);
    insert(&A,22);
    insert(&A,17);
    insert(&A,32);
    insert(&B,16);
    insert(&B,2);
    insert(&B,9);
    insert(&B,13);
    insert(&B,37);
    insert(&B,8);
    insert(&B,10);
    insert(&B,1);
    insert(&B,28);
    printf("List A:\n");
    print(A);
    printf("\n\n");
    printf("List B:\n");
    print(B);
    C=common(A,B);
    printf("\n\n");
    printf("common values are:\n");
    print(C);
    printf("\n\n");
    printf("After combining:\n");
    D=combine(A,B);
    print(D);


}