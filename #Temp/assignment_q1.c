#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL;
void create(int *num) 
{
    struct node *temp;
    if (*num>=1)
    {
        printf("Enter data:");
        head=temp=malloc(sizeof (struct node));
        scanf("%d",&head->data);
        temp->prev=temp;
        temp->next=temp;

    }
    
    for(int i=2;i<=*num;i++)
    {
        struct node *newnode;
        newnode=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        head->prev=newnode;
        newnode->prev=temp;
        newnode->next=head;
        temp->next=newnode;
        temp=newnode;

    }
}
    
void print()
{
    if (head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("The elements of Linked List are:\n");
    struct node *current=head;
    do
    {
        printf("%d\n",current->data);
        current=current->next;
    } while (current!=head);
    
}

void insert_at_beg()
{
    struct node *newnode=malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    if (head==NULL)
    {
        head=newnode;
        head->prev=head->next=newnode;
    }
    else
    {
        struct node *current=head;
        while (current->next!=head)
        {
            current=current->next;
        }
        newnode->next=head;
        newnode->prev=current;
        head=newnode;
        current->next=head;
    }
}

int length()
{
    int count=1;
    if (head==NULL)
    count=0;
    else
    {
        struct node *current=head;
        while(current->next!=head)
        {
            count++;
            current=current->next;
        }
    }
    return count;
}
void insert_at_end()
{
    struct node *current=head;
    while (current->next!=head)
    {
        current=current->next;
    }
    struct node *newnode=malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&newnode->data);
    newnode->prev=current;
    newnode->next=head;
    current->next=newnode;
}
void insert_at_pos()
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    int count=length();
    if(pos>count+1)
    {
        printf("Invalid Position\n");
        return ;
    }
    if (pos<1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        insert_at_beg();
    }
    else if(pos==count)
    {
        insert_at_end();
    }
    else
    {
        int i;
        struct node *before=head,*after=head->next;
        for(i=1;i<pos-1;i++)
        {
            before=before->next;
            after=after->next;
        }
        struct node *newnode=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&newnode->data);
        newnode->prev=before;
        newnode->next=after;
        before->next=after->prev=newnode;
    }
}

void delete_at_beg()
{
    if (head==NULL)
    {
        printf("The list is already empty\n");
        return;
    }
    struct node *temp=head,*current=head;
    while(current->next!=head)
    {
        current=current->next;
    }
    head=head->next;
    current->next=head;
    free(temp);
}
void delete_at_pos()
{
    int pos;
    printf("Enter position:");
    scanf("%d",&pos);
    int count=length();
    if (pos>count)
    {
        printf("Invalid Position\n");
        return;
    }
    if (pos<1)
    {
        printf("Invalid Position\n");
        return;
    }
    if (pos==1)
    {
        delete_at_beg();
        return;
    }

    struct node *current=head;
    for(int i=2;i<=pos;i++)
    {
        current=current->next;
    }
    current->prev->next=current->next;
    current->next->prev=current->prev;
    free(current);
}
void delete_at_end()
{
    struct node *current=head;
    while(current->next!=head)
    {
        current=current->next;
    }
    head->prev=current->prev;
    current->prev->next=head;
    free(current);
}

int main()
{
    int num;
    printf("Enter number of elements:");
    scanf("%d",&num);
    create(&num);
    print();
    printf("Insert at beg\n");
    insert_at_beg();
    print();
    printf("Insert at pos\n");
    insert_at_pos();
    print();
    printf("Insert at end\n");
    insert_at_end();
    print();
    printf("delete at beg\n");
    delete_at_beg();
    print();
    printf("delete at pos\n");
    delete_at_pos();
    print();
    printf("delete at end\n");
    delete_at_end();
    print();

}