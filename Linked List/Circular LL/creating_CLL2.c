//singly linked list using tail

#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
void create(struct node **tail)
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
        if(*tail==NULL)
        {
            *tail=temp=newnode;
            newnode->link=*tail;
        }
        else
        {
            newnode->link=(*tail)->link;
            (*tail)->link=newnode;
            (*tail)=newnode;
        }
    }
}

void print(struct node *tail)
{
    struct node *temp=tail->link;
    do
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    } while(temp!=tail->link);

}    


int main()
{
    struct node *tail=NULL;
    create(&tail);
    print(tail);

}
