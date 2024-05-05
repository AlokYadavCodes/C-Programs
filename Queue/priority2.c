#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node 
{
    char ch;
    int priority;
};
struct node queue[MAX];
int front=-1,rear=-1;

void enqueue(char ch,int priority)
{
    if(front==-1)
    {
        front=rear=0;
        queue[rear].ch=ch;
        queue[rear].priority=priority;
    }
    else if ((front==0 && rear==MAX-1) || rear+1==front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(queue[front].priority>priority)
        {
            if(front==0)
            {
                front=MAX-1;
                queue[front].ch=ch;
                queue[front].priority=priority;
            }
            else
            {
                front--;
                queue[front].ch=ch;
                queue[front].priority=priority;         
            }
            return;
        }
        int i=front;
        while(i!=rear+1 && queue[i].priority<=priority)
            i=(i+1)%MAX;
        for(int j=rear;j>=i;j--)
        {
            queue[j+1]=queue[j];
        }
        queue[i].ch=ch;
        queue[i].priority=priority;
        rear=(rear+1)%MAX;
    }
}

char dequeue()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    char ch=queue[front].ch;
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%MAX;
    return ch;
}

void print()
{
    if(front==-1)
    {
        printf("Queue Underflow\n");
        return;
    }
    int i=front;
    do
    {
        printf(" %c ",queue[i].ch);
        i=(i+1)%MAX;
    } while(i!=(rear+1)%MAX);
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
}
