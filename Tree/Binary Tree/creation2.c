#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left,*right;
    char data;
};

struct node* CreateTree();
struct node* addNode();

struct node* CreateTree()
{
    char c;
    printf("Enter the root element: ");  
    scanf(" %c",&c);
    if(c=='0')
        return NULL;
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->data=c;
    printf("Enter the left node of %c: ",c);
    root->left=addNode();
    printf("Enter the right node of %c: ",c);
    root->right=addNode();
    return root;
}

struct node* addNode()
{
    char c;
    scanf(" %c",&c);
    if(c=='0')
        return NULL;
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=c;
    printf("Enter the left node of %c: ",c);
    newnode->left=addNode();
    printf("Enter the right node of %c: ",c);
    newnode->right=addNode();
    return newnode;
}

int main()
{
    struct node *root=CreateTree();
    return 0;
}