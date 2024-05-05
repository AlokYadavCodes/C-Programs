#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp=top;
    int value=top->data;
    top=top->link;
    free(temp); temp=NULL;
    return value;
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return top->data;
}

void print()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp=top;
    printf("Stack elements are: ");
    while(temp)
    {
        printf("%d  ",temp->data);
        temp=temp->link;
    }
}

int main()
{
    while (1)
    {
        printf("\n 1.Push \n 2.Pop\n 3.Print the top element\n 4.Print all the elements \n 5.Quit\n");
        printf("Enter your choice:");
        int choice,data;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element to push:");
            scanf("%d",&data);
            push(data);
            break;

            case 2:
            data=pop();
            printf("Deleted element is %d\n",data);
            break;

            case 3:
            printf("Topmost element is %d\n",peek());
            break;

            case 4:
            print();
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid Choice\n");

        }
    }
    
    return 0;
}