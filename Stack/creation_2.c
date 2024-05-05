// stack_arr[0] as top element

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int first=-1;

int isFull()
{
    if(first==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(first==-1)
        return 1; 
    else 
        return 0;
}

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    first++;
    for(int i=first;i>0;i--)
    {
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data; 
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value=stack_arr[0];
    first--;
    for(int i=0;i<=first;i++)
    {
        stack_arr[i]=stack_arr[i+1];
    }
    return value;
}

int peek()
{
    if(isEmpty())
    {
        printf("The list is empty\n");
        exit(1);

    }
    return stack_arr[0];
}

void print()
{
    if (isEmpty())
    {
        printf("The list is empty\n");
        return;
    }
    for(int i=0;i<=first;i++)
    {
        printf("%d\t",stack_arr[i]);
    } 
    printf("\n");

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
            printf("Elements in the stack are:  ");
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