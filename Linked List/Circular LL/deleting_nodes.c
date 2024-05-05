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

void delFirst(struct node **tail)
{
    struct node *temp=(*tail)->link;
    (*tail)->link=(*tail)->link->link;
    free(temp); temp=NULL;
}

void delLast(struct node **tail)
{
    struct node *temp=*tail;
    while(temp->link!=*tail)
    {
        temp=temp->link;
    }
    temp->link=(*tail)->link;
    struct node *temp2=*tail;
    *tail=temp;
    free(temp2); temp2=NULL;
}

int length(struct node *tail)
{
    int count=1;
    if(tail==NULL) return 0;
    struct node *temp=tail->link;
    while(temp!=tail)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void delNode(struct node **tail,int n)
{
    if(n<1)
    {
        printf("Invalid Input\n");
        return ;
    }
    if(n==1)
    {
        delFirst(tail);
        return;
    }
    if (n==length(*tail))
    {
        delLast(tail);
        return;
    }
    struct node *temp=*tail;
    while(n!=1)
    {
        temp=temp->link;
        n--;
    }
    struct node *temp2=temp->link;
    temp->link=temp->link->link;
    free(temp2); temp2=NULL;


}

void search(struct node *tail,int element)
{
    if(tail==NULL)
    {
        printf("The list is already empty\n");
        return ;
    }
    int index=0;
    struct node *temp=tail->link;
    while(temp->data!=element)
    {
        index++;
        temp=temp->link;
        if(temp==tail->link)
        {
            printf("Element not present in the list\n");
            return;
        }
    }
    printf("The element %d is present at the index %d",element,index);
    return;

}


int main()
{
    struct node *tail=NULL;
    create(&tail);
    print(tail);
    // delFirst(&tail);
    // printf("\nAfter deleting first node:\n");
    // print(tail);
    // delLast(&tail);
    // printf("\nAfter deleting last node:\n");
    // print(tail);
    // printf("Enter the node you want to delete:");
    // int n;
    // scanf("%d",&n);
    // delNode(&tail,n);
    // printf("\nAfter deleting %d node:\n",n);
    // print(tail);
    printf("Enter the element to search:");
    int element;
    scanf("%d",&element);
    search(tail,element);

    return 0;
}
