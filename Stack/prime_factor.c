#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int stack_arr[MAX];
int top=-1;

void push(int data)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack_arr[top]=data;
}

void prime(int num)
{
    int i=2;
    if(num<0)
    {
        printf("Please enter a positive number\n");
        return;
    }
    while(num!=1)
    {
        if(num%i!=0)
        {
            i++;
            continue;
        }
        num=num/i;
        push(i);
    }
}

void print()
{
    if(top==-1)
    {
        printf("No prime_no factors\n");
        return;
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d",stack_arr[i]);
        if(i>0)
            printf("*");
    }
}

int main()
{
    printf("Enter the number:");
    int num;
    scanf("%d",&num);
    prime(num);
    print();
}