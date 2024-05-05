#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node *queue[MAX];
int rear=-1;
int front=-1;

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

void enque(struct node *node)
{
    if(rear==MAX-1)
    {
        printf("queue Overflow\n");
        exit(1);
    }
    queue[++rear]=node;
}

struct node* pop()
{
    if(rear==-1)
    {
        printf("queue Underflow");
        exit(1);
    }
    struct node *ptr=queue[rear];
    rear--;
    return ptr;
}

int isEmpty()
{
    int a,b;
    if(rear==-1)
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
    enque(root);
    while(isEmpty)
    {
        ptr=pop();
        printf("%d ",ptr->data);
        if(ptr->right)
            enque(ptr->right);
        if(ptr->left)
            enque(ptr->left);
    }
}

int main()
{
    struct node *root=CreateTree();
    preorder(root);
    return 0;
}