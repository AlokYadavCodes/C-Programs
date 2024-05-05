#include<stdio.h>
#include<stdlib.h>
struct term
{
    int coeff,expo;
    struct term *link;
};

void create (struct term **poly);
void insert(struct term **poly,int coeff,int expo);
void print(struct term *poly);
struct term *add(struct term *poly1,struct term *poly2);

void create(struct term **poly)
{
    int n;
    printf("Enter the number of terms:");
    scanf("%d",&n);
    int coeff,expo;
    for(int i=0;i<n;i++)
    {
        printf("Enter the coefficient of the term %d:",i+1);
        scanf("%d",&coeff);
        printf("Enter the exponent of the term %d:",i+1);
        scanf("%d",&expo);
        insert(poly,coeff,expo);
    } 
    return;
}

// void insert(struct term **poly,int coeff,int expo)
// {
//     struct term *newterm=malloc(sizeof(struct term));
//     if(newterm==NULL)
//     {
//         printf("Memory is full\n");
//         return;
//     }
//     newterm->coeff=coeff;
//     newterm->expo=expo;
//     if(*poly==NULL || newterm->expo>(*poly)->expo)
//     {
//         newterm->link=*poly;
//         *poly=newterm;
//     }
//     else if(newterm->expo==(*poly)->expo)
//     {
//         (*poly)->coeff=(*poly)->coeff+newterm->coeff;
//     }
//     else
//     {
//         struct term *temp=*poly;
//         while(temp->link!=NULL && temp->link->expo>newterm->expo)
//         {
//             temp=temp->link;
//         }
//         if(temp->link!=NULL && newterm->expo==temp->link->expo)
//         {
//             temp->link->coeff=temp->link->coeff+newterm->coeff;
//         }
//         else
//         {
//             newterm->link=temp->link;
//             temp->link=newterm;
//         }
        
//     }
// }

void insert(struct term **poly,int coeff,int expo)
{
    struct term *newterm=malloc(sizeof(struct term));
    if (newterm==NULL)
    {
        printf("Memory is full!\n");
        exit(1);
    }
    newterm->coeff=coeff;
    newterm->expo=expo;
    if(*poly==NULL || newterm->expo > (*poly)->expo)
    {
        newterm->link=*poly;
        *poly=newterm;
    }
    else
    {
        struct term *current=*poly,*prev;
        while(current!=NULL && current->expo > newterm->expo)
        {
            prev=current;
            current=current->link;
        }
        if(current!=NULL && current->expo==newterm->expo)
        {
            current->coeff=current->coeff+newterm->coeff;
            free(newterm);
            newterm=NULL;
            return;
        }
        newterm->link=prev->link;
        prev->link=newterm;
    }
}

void print(struct term *poly)
{
    struct term *temp=poly;
    while(temp)
    {
        printf("(%dx^%d)",temp->coeff,temp->expo);
        temp=temp->link;
        if(temp)
            printf("+");
    }
}

struct term *add(struct term *poly1,struct term *poly2)
{
    struct term *result=NULL;
    struct term *temp1=poly1,*temp2=poly2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->expo>temp2->expo)
        {
            insert(&result,temp1->coeff,temp1->expo);
            temp1=temp1->link;
        }
        else if(temp2->expo>temp1->expo)
        {
            insert(&result,temp2->coeff,temp2->expo);
            temp2=temp2->link;
        }
        else
        {
            insert(&result,temp1->coeff+temp2->coeff,temp1->expo);
            temp1=temp1->link;
            temp2=temp2->link;
        }
    }
    while(temp1!=NULL)
    {
        insert(&result,temp1->coeff,temp1->expo);
        temp1=temp1->link;
    }
    while(temp2!=NULL)
    {
        insert(&result,temp2->coeff,temp2->expo);
        temp2=temp2->link;
    }
    return result;
}

int main ()
{
    struct term *poly1=NULL,*poly2=NULL,*poly3=NULL;
    printf("\nEnter the values for Polynomial 1:\n");
    create(&poly1);
    printf("\nEnter the values for Polynomial 2:\n");
    create(&poly2);
    printf("\nPolynomial 1 is:");
    print(poly1);
    printf("\nPolynomial 2 is:");
    print(poly2);
    poly3=add(poly1,poly2);
    printf("\nAfter addition:");
    print(poly3);
    printf("\n\nProgram Ended:)");
    return 0;
}