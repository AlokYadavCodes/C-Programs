#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int deque[MAX];
int front=-1,rear=-1;

int isEmpty()
{
    if(front==-1)
        return 1;
    else 
        return 0;
}

int isFull()
{
    if(front==(rear+1)%MAX)
        return 1;
    else 
        return 0;
}

void enqueueAtFront(int data)
{
    if(isFull())
    {
        printf("Queue Overflow");
        exit(1);
    }
    if(isEmpty())
        front=rear=0;
    else if(front==0)
        front=MAX-1;
    else 
        front--;
    deque[front]=data;

}


void enqueueAtRear(int data)
{
    if(isFull())
    {
        printf("Queue Overflow");
        exit(1);
    }
    if(isEmpty())
        front=rear=0;
    else
        rear=(rear+1)%MAX;
    deque[rear]=data;
}

int dequeueAtFront()
{
    int val;
    if(isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    val=deque[front];
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
    return val;
}

int dequeueAtRear()
{
    if(isEmpty())
    {
        printf("Queue Underflow");
        exit(1);
    }
    int val=deque[rear];
    if(front==rear)
        front=rear=-1;
    else if(rear==0)
        rear=MAX-1;
    else 
        rear--;
    return val;
}

int peek()
{
    if(isEmpty())
    {
        printf("The queue is empty!");
        exit(1);
    }
    return deque[front];
}

void print()
{
    if(isEmpty())
    {
        printf("The queue is empty!");
        return ;
    }
    int i=front;
    do 
    {
        printf("%d ",deque[i]);
        i=(i+1)%MAX;
    }while(i!=(rear+1)%MAX);
    
}

int main()
{
    int data,val;
    while(1)
    {
        printf("\n1.Enqueue at Front \n2.Enqueue at Rear \n3.Dequeue at Front \n4.Dequeue at Rear \n5.Print the first element \n6.Print \n7.Exit \n");
        int choice;
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            data;
            printf("Enter the element:");
            scanf("%d",&data);
            enqueueAtFront(data);
            printf("Element is inserted at front in the queue successfully.");
            break;

            case 2:
            data;
            printf("Enter the element:");
            scanf("%d",&data);
            enqueueAtRear(data);
            printf("Element is inserted at rear in the queue successfully.");
            break;

            case 3:
            val=dequeueAtFront();
            printf("Deleted element from front was %d\n",val);
            break;

            case 4:
            val=dequeueAtRear();
            printf("Deleted element from rear was %d\n",val);
            break;

            case 5:
            printf("The first element is %d\n",peek());
            break;

            case 6:
            print();
            break;
            
            case 7:
            exit(0);

            default:
            printf("Invalid Choice.\t Try again\n");
        }
    }
    return 0;
}