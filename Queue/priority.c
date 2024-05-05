#include<stdio.h>
#include<stdlib.h>
struct node 
{
    char ch;
    int priority;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;

void enqueue(char ch,int priority)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->ch=ch;
    newnode->priority=priority;
    if(rear==NULL || newnode->priority<front->priority)
    {
        newnode->link=front;
        front=rear=newnode;
        return;
    }
    struct node *temp=front;
    while(temp->link!=NULL && temp->link->priority<=newnode->priority)
    {
        temp=temp->link;
    }
    newnode->link=temp->link;
    temp->link=newnode;

    // to update rear
    if(newnode->link==NULL)
        rear=newnode;
}

char dequeue()
{
    if(front==NULL)
    {
        printf("Queue Underflow");
        exit(1);
    }
    char ch=front->ch;
    struct node *temp=front;
    front=front->link;
    free(temp);

    return ch;
}

void print()
{
    if(front==NULL)
    {
        printf("The queue is empty\n");
        return;
    }
    struct node *temp=front;
    while(temp)
    {
        printf("%c ",temp->ch);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    int choice,priority;
    char ch;
    while(1)
    {
        printf("\n 1.Enqueue \n 2.Dequeue \n 3.Print\n 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            printf("Enter the character:");
            scanf(" %c",&ch);
            printf("Enter priority:");
            scanf("%d",&priority);
            enqueue(ch,priority);
            printf("Element is inserted successfully\n");
            break;

            case 2:
            char ch=dequeue();
            printf("Deleted element is: %c\n",ch);
            break;

            case 3:
            printf("\nElements of the Queue are:");
            print();
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}