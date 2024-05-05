#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front=NULL,*rear=NULL;

int isEmpty()
{
    if(front==NULL)
        return 1;
    else 
        return 0;
}

void enqueue(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Queue Overflow!\n");
        exit(1);
    }
    newnode->data=data;
    newnode->link=NULL;
    if(isEmpty())
        front=rear=newnode;
    else  //rear=rear->link=newnode;
    {
        rear->link=newnode;
        rear=newnode;
    }
        
}

int dequeue()
{
    if(isEmpty())
    {
        printf("Queue Underflow!\n");
        exit(1);
    }
    struct node *temp=front;
    int val=temp->data;
    if(front==rear)
        front=rear=NULL;
    else
        front=front->link;
    free(temp);
    temp=NULL;
    return val;
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue is empty.");
        exit(1);
    }
    return front->data;
}

void print()
{
    if(isEmpty())
    {
        printf("Queue is empty.");
        exit(1);
    }
    struct node *temp=front;
    printf("Elements in the Queue are:");
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main()
{
    while(1)
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Print the first element \n4.Print \n5.Exit \n");
        int choice;
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            int data;
            printf("Enter the element:");
            scanf("%d",&data);
            enqueue(data);
            printf("Element is inserted in the queue successfully.");
            break;

            case 2:
            int val=dequeue();
            printf("Deleted element was %d\n",val);
            break;

            case 3:
            printf("The peek element is %d\n",peek());
            break;

            case 4:
            print();
            break;
            
            case 5:
            exit(0);

            default:
            printf("Invalid Choice.\t Try again\n");
        }
    }
    return 0;
}