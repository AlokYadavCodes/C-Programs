#include <stdio.h>
#include <string.h>
int s[100];
struct node {
    char ch;
    struct node *link;
};
struct node *top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(char ch)
{
    struct node *newnode=malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    newnode->ch=ch;
    newnode->link=top;
    top=newnode;
}

char pop()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct node *temp=top;
    char value=top->ch;
    top=top->link;
    free(temp); temp=NULL;
    return value;
}


// isValilds()
// {
//     for(int i=0; i<strlen(s);i++)
//     {
//         if(s[i]=='[' || s[i]=='{' || s[i]=='(')
//             push(s[i]);
        
//         if(s[i]==']' || s[i]=='}' || s[i]==')')
//         {
//             char ch=pop();
//             if(ch!=)
//         }
        
//     }

// }


int main()
{   
    printf("Enter the s:");
    scanf("%s",&s);



    return 0;
}