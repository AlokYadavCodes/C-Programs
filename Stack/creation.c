#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;

int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top==-1)
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
    top++;
    stack_arr[top]=data;
}

int pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value=stack_arr[top];
    top--;
    return value;
}

int peek()
{
    if(isEmpty())
    {
        printf("The list is empty\n");
        exit(1);
    }
    return stack_arr[top];
}

void print()
{
    if (isEmpty())
    {
        printf("The list is empty\n");
        return;
    }
    for(int i=top;i>=0;i--)
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