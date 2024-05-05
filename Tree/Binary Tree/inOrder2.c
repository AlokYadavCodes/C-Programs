//non-recursive implementation of inorder
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node *stack[MAX];
int top=-1;

struct node
{
    int data;
    struct node *left,*right;
};

struct node* CreateTree()
{
    printf("Enter the element:");
    int c;
    scanf(" %d",&c);
    if (c==0)
    {
        return NULL;
    }
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=c;
    printf ("For the left child of %d,",c);
    newnode->left=CreateTree(newnode->left);
    printf ("For the right child of %d,",c);
    newnode->right=CreateTree(newnode->right);
    return newnode;
}

void push(struct node *node)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top]=node;
}

struct node* pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    struct node *ptr=stack[top];
    top--;
    return ptr;
}

int isEmpty()
{
    if(top==-1)
        return 1;
    else 
        return 0;
}


void inorder(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL)
    {
        printf("The Tree is Empty");
        return ;
    }
    push(ptr);
    while(!isEmpty())
    {
        while(ptr->left)
        {
            ptr=ptr->left;
            push(ptr);
        }
        ptr=pop();
        printf("%d ",ptr->data);
        if(ptr->right)
        {
            ptr=ptr->right;
            push(ptr);
        }
    }
}


int main()
{
    struct node *root=CreateTree();
    inorder(root);
    return 0;
}