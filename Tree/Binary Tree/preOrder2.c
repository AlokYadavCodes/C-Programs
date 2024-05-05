//non-recursive implementation of preorder
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


void preorder(struct node *root)
{
    struct node *ptr=root;
    if(ptr==NULL)
    {
        printf("The Tree is Empty");
        return;
    }
    push(root);
    while(isEmpty)
    {
        ptr=pop();
        printf("%d ",ptr->data);
        if(ptr->right)
            push(ptr->right);
        if(ptr->left)
            push(ptr->left);
    }
}

int main()
{
    struct node *root=CreateTree();
    preorder(root);
    return 0;
}