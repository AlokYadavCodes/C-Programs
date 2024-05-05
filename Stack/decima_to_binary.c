#include<stdio.h>
#include<stdlib.h>
#define MAX 50
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
    while(isEmpty)
    {
        printf("%d\t",pop());
    } 
    printf("\n");

}

void dec2bin(int num)
{
    if(num<0)
    {
        printf("Please enter a positive number\n");
        return;
    }
    if(num==0 || num==1)
    {
        push(num);
        return;
    }
    while(num!=0)
    {
        push(num%2);
        num=num/2;
    }
}

int main()
{
    printf("Enter the number:");
    int num;
    scanf("%d",&num);
    dec2bin(num);
    printf("The binary equivalent of %d is:",num);
    while(top!=-1)
    {
        printf("%d",pop());
    }
       
    
    return 0;
}