#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL,*temp,*newnode;
void create(int *Num)
{
    if (*Num>=1)
    {
        head=temp=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&head->data);
        head->link=NULL;

        for (int i=2;i<=*Num;i++)
        {
            newnode=malloc (sizeof(struct node));
            printf("Enter data:");
            scanf("%d",&newnode->data);
            temp->link=newnode;
            newnode->link=NULL;
            temp=newnode;
        }
        printf("Elements entered successfully!\n");
    }
    else
    printf("You choose to enter nothing\n");

}

void delete_at_end(struct node *current, int *Choice,int *Num)
{
    struct node *prev=NULL;
    if(*Num>1)
    {
        while(current->link!=NULL)
        {    
            prev=current;
            current=current->link;
        }
    prev->link=NULL;
    free(current);
    printf("Do you want to delete again the last element ? Press 1:");
    scanf("%d",Choice);
    }
    else if (*Num==1)
    {
        free(current);
        printf("Do you want to delete again the last element ? Press 1:");
        scanf("%d",Choice);
    }
    else
    {
    printf("There is no element to delete. The list is already empty.\n");
    *Choice=0;
    }

}


int main()
{
    int num;
    printf("How many elements do you want to enter ? ");
    scanf("%d",&num);
    create(&num);

    int choice;
    printf("Do you want to delete the last element? Press 1:");
    scanf("%d",&choice);
    while(choice==1)
    {
        delete_at_end(head,&choice,&num);
        num--;
    }
    if(head==NULL)
    printf("There is no element to display\nThe list is empty\n");
    else
    {
        printf("Here's the final list:\n");
        struct node *current=head;
        while(current!=NULL)
        {
            printf("%d\n",current->data);
            current=current->link;
        }
    }
    
    printf("Program Ended :)");
    return 0;
}