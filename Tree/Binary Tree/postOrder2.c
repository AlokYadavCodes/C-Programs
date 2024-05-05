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

// void postorder(struct node *root)
// {
//     struct node *ptr=root;
//     if (ptr==NULL)
//     {
//         printf("The tree is empty!\n");
//     }
//     push(ptr);
//     while(!isEmpty())
//     {
//         while (ptr->left)
//         {
//             ptr=ptr->left;
//             push(ptr);
//         }
//         while(ptr->right==NULL)
//         {
//             ptr=pop();
//             printf("%d",ptr->data);
//             if(top==-1)
//                 exit(0);
//             if(stack[top]->right==ptr)
//                 {
//                     ptr=pop();
//                     printf("%d",ptr->data);
//                 }
//             ptr=stack[top];
//         }
//         ptr=ptr->right;
//         push(ptr);
        
//     }
// }


void postorder(struct node *root)
{
    struct node *ptr=root;
    struct node *temp=root;
    if(ptr==NULL)
    {
        printf("The Tree is already empty!\n");
        return;
    }
    while(1)
    {
        while(ptr->left)
        {
            push(ptr);
            ptr=ptr->left;
            temp=ptr;
        }
        while(ptr->right==NULL || ptr->right==temp)
        {
            printf("%d ",ptr->data);
            if(top==-1)
                return;
            temp=ptr;
            ptr=pop();
        }
        if(ptr->right)
        {
            push(ptr);
            ptr=ptr->right;
            temp=ptr;
        }
    }
}

int main()
{
    struct node *root=CreateTree();
    postorder(root);
    return 0;
}