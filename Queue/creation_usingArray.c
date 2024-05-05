#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front=-1;
int rear=-1;

int isEmpty()
{
    if(front==-1 || front==rear+1)
        return 1;
    else 
        return 0;
}

int isFull()
{
    if (rear==MAX-1)
        return 1;
    else 
        return 0;
}

void enqueue(int data)
{
    if(isFull())
    {
        printf("Queue Overflow");
        return;
    }
    if(isEmpty())
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}

int dequeue()
{
    int val;
    if(isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    val=queue[front];
    front++;
    return val;
}

int peek()
{
    if(isEmpty())
    {
        printf("The queue is empty\n");
        exit(1);
    }
    return queue[front];
}

void print()
{
    if(isEmpty())
    {
        printf("The queue is empty!\n");
        return;
    }
    printf("Elements in the Queue are:");
    for(int i=front; i<=rear;i++)
    {
        printf("%d ",queue[i]);
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