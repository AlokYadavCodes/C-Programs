#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
struct node *head=NULL,*tail=NULL;

void createList(int n)
{
    head=NULL;
    int data;
    struct node *newnode;
    for (int i=1;i<=n;i++)
    {
        newnode=malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory is full!");
            break;
        }
        printf("\nEnter the element for node %d :",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->link=NULL;
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->link=newnode;
            tail=tail->link;
        }
    }
}

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
        printf("The list is already empty!");
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

void insert_at_end(int data)
{
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory is full!\n");
        return;
    }
    if(head==NULL)
    {
        insert_at_beg(data);
        return;
    }
    newnode->data=data;
    newnode->link=NULL;
    tail->link=newnode;
    tail=tail->link;
}

int delete_at_end(int *val)
{
    if(head==NULL)
    {
        printf("The list is already empty!");
        return 1;
    }
    struct node *current=head,*prev=NULL;
    if(head->link==NULL)
    {
        *val=tail->data;
        head=tail=NULL;
    }
    else
    {
        while(current!=tail)
        {
            prev=current;
            current=current->link;
        }
        *val=current->data;
        prev->link=current->link;
        tail=prev;
    }
    free(current);
    current=NULL;
    return 0;
}

int length()
{
    int count=0;
    struct node *temp=head;
    while(temp)
    {
        count++;
        temp=temp->link;
    }
    return count;
}

void insert_at_pos(int data, int pos)
{
    if(pos<1 || pos>length()+1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
        insert_at_beg(data);
    else if(pos==length())
        insert_at_end(data);
    else
    {
        struct node *newnode=malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory is Full!\n");
            return;
        }
        newnode->data=data;
        int i=1;
        struct node *temp=head;
        while(i!=pos-1)
        {
            temp=temp->link;
            i++;
        }
        newnode->link=temp->link;
        temp->link=newnode;
    }
}

int delete_at_pos(int pos,int *val)
{
    if(pos<1 || pos>length())
    {
        printf("Invalid Position\n");
        return 1;
    }
    int value;
    if(pos==1)
    {
        delete_at_beg(&value);
        *val=value;
        return 0;
    } 
    else if(pos==length())
    {
        delete_at_end(&value);
        *val=value;
        return 0;
    }
    else
    {
        int i=1;
        struct node *current=head;
        while(i!=pos-1) 
        {
            current=current->link; 
            i++;
        }
        struct node *temp=current->link;
        *val=temp->data;
        current->link=current->link->link;
        free(temp);
        temp=NULL;
        return 0;
    }
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

void reverse()
{
    if(head==NULL)
    {
        printf("The list is empty!\n");
        return;
    }
    tail=head;
    struct node *prev=NULL,*current,*next;
    current=next=head;
    while(next)
    {
        next=next->link;
        current->link=prev;
        prev=current;
        current=next;
    }
    head=prev;
    printf("\nThe list is reversed successfully.\n");
}

int main()
{
    while(1)
    {
        int choice;
        printf("\n1. Create a List \n2. Insert at beginning \n3. Delete at beginning \n4. Insert at end \n5. Delete at end  \n6. Insert at Position \n7. Delete at position \n8. Print the list \n9. Reverse the list \n10. Quit \n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        int status,value,data,pos;
        switch(choice)
        {
            case 1:
            int num;
            printf("Enter the number of elements you want to enter in the list:");
            scanf("%d",&num);
            createList(num);
            printf("List created successfully\n");
            break;

            case 2:
            printf("Enter the element:");
            scanf("%d",&data);
            insert_at_beg(data);
            printf("Element inserted successfully.\n");
            break;

            case 3:
            status=delete_at_beg(&value);
            if(status==0)
                printf("Deleted element was %d\n",value);
            break;

            case 4:
            printf("Enter the element:");
            scanf("%d",&data);
            insert_at_end(data);
            printf("Element inserted successfully.\n");
            break;

            case 5:
            status=delete_at_end(&value);
            if(status==0)
                printf("Deleted element was %d\n",value);
            break;

            case 6:
            printf("Enter the positon:");
            scanf("%d",&pos);
            printf("Enter the element to enter at node %d: ",pos);
            scanf("%d",&data);
            insert_at_pos(data,pos);
            printf("Element inserted successfully.\n");
            break;

            case 7:
            printf("Enter the positon:");
            scanf("%d",&pos);
            status=delete_at_pos(pos,&value);
            if(status==0)
                printf("Deleted element was %d\n",value);
            break;

            case 8:
            print();
            break;

            case 9:
            reverse();
            break;

            case 10:
            exit(0);

            default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}