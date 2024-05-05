#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left,*right;
    char data;
};

struct node* CreateTree();
struct node* addNode(char parent);
struct node* addright(char parent);

struct node* CreateTree()
{
    char c;
    printf("enter the element: ");
    scanf(" %c",&c);
    if(c=='0')
        return NULL;
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->data=c;
    printf("For the  left node of %c, ",c);
    root->left=CreateTree();
    printf("For the right node of %c, ",c);
    root->right=CreateTree();
    return root;
}

int countNodes(struct node *root)
{
    if (root==NULL)
    {
        return  0;
    }
    int left=0,right=0;
    left=countNodes(root->left);
    right=countNodes(root->right);
    return left+right+1;
}

int main()
{
    struct node *root=CreateTree();
    int count=countNodes(root);
    printf("\nNumber of Nodes are: %d",count);
    return 0;
}