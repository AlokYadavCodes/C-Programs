#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *link;
};
void del_at_beg(struct node **Head,int *Choice)
{
    struct node *temp;
    temp=*Head;
    *Head=(*Head)->link;
    free(temp);
    printf("Do you want to delete again the first element from the remaining? Press 1:");
    scanf("%d",Choice);
}
int main()
{
    int num;
    struct node *head=NULL,*temp,*newnode;
    printf("How many elements do you want to enter?");
    scanf("%d",&num);
    if (num<1)
    printf("You choose to enter nothing\n");
    else
    {
        head=malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d",&head->data);
        temp=head;
        temp->link=NULL;

        for (int i=2; i<=num; i++)
        {
            newnode=malloc(sizeof (struct node));
            printf("Enter data:");
            scanf("%d",&newnode->data);
            temp->link=newnode;
            newnode->link=NULL;
            temp=newnode;
        }
        printf("Elements entered successfully!\n");
    }
    int choice=0;
    printf("Do you want to delete the first element from the list? Press 1\n");
    scanf("%d",&choice);
    {
        while (choice==1)
        {
            if (num>=1)
            {
                num--;
                del_at_beg(&head,&choice);
            }
            else 
            {printf("The list is already empty\n");
            return 0;}
        }
    }
    

    printf("The final list is :\n");
    temp=head;
    if(temp==NULL) printf("There is no element in the list\n");
    else
    {
        while (temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
    printf("Program Ended :)");
    return 0;
}