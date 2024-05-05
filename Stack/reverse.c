//reversing a stack using two temporary stacks

#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *top0=NULL,*top1=NULL,*top2=NULL;

int isEmpty(struct node *top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(struct node **top,int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    newnode->data=data;
    newnode->link=*top;
    *top=newnode;
}

int pop(struct node **top)
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    int value=(*top)->data;
    struct node *temp=*top;
    *top=(*top)->link;
    free(temp); temp=NULL;
    return value;
}

void reverse()
{
    while(!isEmpty(top0))
    {
        push(&top1,pop(&top0));
    }

    while(!isEmpty(top1))
    {
        push(&top2,pop(&top1));
    }

    while(!isEmpty(top2))
    {
        push(&top0,pop(&top2));
    }

}

void print(struct node *top)
{
    if(top==NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
    struct node *temp=top;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
}

int main()
{
    while (1)
    {
        printf("\n 1.Push \n 2.Pop\n 3.Print \n 4.Reverse \n 5.Quit\n");
        printf("Enter your choice:");
        int choice,data;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element to push:");
            scanf("%d",&data);
            push(&top0,data);
            break;

            case 2:
            data=pop(&top0);
            printf("Deleted element is %d\n",data);
            break;

            case 3:
            printf("Elements in the stack are: ");
            print(top0);
            break;

            case 4:
            reverse();
            printf("Elements reversed successfully\n");
            break;

            case 5:
            exit(0);

            default:
            printf("Invalid Choice\n");

        }
    }
    
    return 0;
}