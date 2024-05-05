#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *head=NULL,*tail=NULL;


void insert_at_beg(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is full!");
        return;
    }
    if(head==NULL)
        tail=newnode;
    newnode->data=data;
    newnode->link=head;
    head=newnode;
}


int delete_at_beg(int *val)
{
    if(head==NULL)
    {
        printf("The list is already empty!\n");
        return 1;
    }
    *val=head->data;
    struct node *temp=head;
    if(head->link==NULL)
        head=tail=NULL;
    else
        head=head->link;
    free(temp);
    temp=NULL;
    return 0;
}


void print()
{
    if(head==NULL)
    {
        printf("The list is empty!");
        return ;
    }
    struct node *temp=head;
    printf("\nElements in the list are:");
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
        int choice;
        printf("\n1. Insert at beginning \n2. Delete at beginning \n3. Print the list \n4. Quit \n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        int status,value,data,pos;
        switch(choice)
        {
            case 1:
            printf("Enter the element:");
            scanf("%d",&data);
            insert_at_beg(data);
            printf("Element inserted successfully.\n");
            break;

            case 2:
            status=delete_at_beg(&value);
            if(status==0)
                printf("Deleted element was %d\n",value);
            break;

            case 3:
            print();
            break;

            case 4:
            exit(0);

            default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}