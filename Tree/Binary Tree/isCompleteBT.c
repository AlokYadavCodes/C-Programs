#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *left,*right;
};

struct node* CreateTree()
{
    printf("Enter the element:");
    char c;
    scanf(" %c",&c);
    if (c=='0')
    {
        return NULL;
    }
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=c;
    printf ("For the left child of %c,",c);
    newnode->left=CreateTree(newnode->left);
    printf ("For the right child of %c,",c);
    newnode->right=CreateTree(newnode->right);
    return newnode;
}

int countNodes(struct node *root)
{
    if (root==NULL)
        return 0;
    int left=0,right=0;
    left=countNodes(root->left);
    right=countNodes(root->right);
    return left+right+1;
}

bool isCompleteBT(struct node *root,int index,int count)
{
    if(root==NULL)
        return true;
    if(index>=count)
    {
        return false;
    }
    bool left,right;
    left=isCompleteBT(root->left,2*index+1,count);
    right=isCompleteBT(root->right,2*index+2,count);
    return left && right;
}



int main()
{
    struct node *root=CreateTree();
    int count=countNodes(root);
    printf("No. of nodes are:%d\n\n",count);
    if(isCompleteBT(root,0,count))
        printf("It is a Complete BT");
    else    
        printf("It's not a Complete BT");

    return 0;
}