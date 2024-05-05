#include <stdio.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int infix[MAX],postfix[MAX];
top=-1;

void inToPost()
{
    int i,j;
    for(i=0;i<strlen(infix);i++)
    {
        char symbol=infix[i], next;
        switch(symbol)
        {
            case '(':
            push(stack);
            break;

            case ')':
            while(next=pop()!='(')
                postfix[j++]=next;
            break;

            case '^':
            case '/':
            case '*':
            case '+':
            case '-':
            while(!isEmpty() && precendence(stack[top])>=precendence(symbol))
                postfix[j++]=pop();
            push(symbol);
            break;    

            default:
            postfix[j++]=symbol;
        }
    }
    while(!isEmpty())
        postfix[j++]=pop();
    postfix[j]='\0';
}

int precendence(char symbol)
{
    switch(symbol)
    {
        case '^':
        return 3;

        case '/':
        case '*':
        return 2;

        case '+':
        case '-':
        return 1;

        default:
        return 0;
    }
}

int main()
{
    printf("Enter the infix expression: ");
    gets(infix);

    return 0;
}