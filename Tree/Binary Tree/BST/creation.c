#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left,*right;
    int data;
};

void insert(struct node **node,int data)
{
    if(*node==NULL)
    {
        struct node *newnode=malloc(sizeof(struct node));
        *node=newnode;
        (*node)->data=data;
        (*node)->left=(*node)->right=NULL;
    }
    else
    {
        if(data<=(*node)->data)
            insert(&((*node)->left),data);
        else
            insert(&((*node)->right),data);
    }
}

void inorder(struct node *node)
{
    if(node)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

void search(struct node *node, int data)
{
    if(node==NULL)
        printf("Not found!");
    else if(data==node->data)
        printf("Element found!");
    else if(data<node->data)
        search(node->left,data);
    else if(data<node->data)
        search(node->right,data);
}

int main()
{
    int num;
    struct node *root=NULL;
    printf("Enter number of nodes you want to enter: ");
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        int data;
        printf("Enter the data:");
        scanf("%d",&data);
        insert(&root,data);
    }

    inorder(root);

    printf("\nEnter the element to search: ");
    int n;
    scanf("%d",&n);
    search(root,n);
}