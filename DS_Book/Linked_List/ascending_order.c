#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
void add(struct node **q,int num)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=num;
    if (*q==NULL)
    {
        *q=newnode;
        newnode->link=NULL;
    }
    else
    {
        struct node *current=*q,*prev=NULL;
        
        while((current!=NULL) && (current->data<num))
        {
            prev=current;
            current=current->link;
        }
        if (current==*q)
        {
            newnode->link=*q;
            *q=newnode;
        }
        else
        {
            newnode->link=prev->link;
            prev->link=newnode;
        }
    }
}
void print(struct node *q)
{
    struct node *temp=q;
    if (temp==NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
// void reverse (struct node **Head,struct node *p)
// {
//     struct node *temp=p;
//     while(temp!=NULL)
//     {
//         struct node *newnode=malloc(sizeof(struct node));
//         newnode->data=temp->data;
//         newnode->link=NULL;
//         if (*Head==NULL)
//         {
//             *Head=newnode;
//         }
//         else
//         {
//             newnode->link=*Head;
//             *Head=newnode;
//         }
//         temp=temp->link;
//     }


// }
void reverse (struct node **x)
{
    struct node *q,*r,*s;
    r=NULL;
    q=*x;
    while(q!=NULL)
    {
        s=r;
        r=q;
        r->link=s;
        q=q->link;
        
    }
    *x=r;
}
int main()
{
    struct node *p=NULL,*head=NULL;
    add(&p,25);
    add(&p,22);
    add(&p,17);
    add(&p,18);
    add(&p,15);
    print(p);
    reverse(&p);
    printf("\n\n\n");
    print(p);
    
}