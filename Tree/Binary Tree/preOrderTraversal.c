#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *left,*right;
    char data;
};

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

void preorder (struct node *root)
{
    if(root==NULL)
    return;
    printf("%c\t",root->data);
    preorder(root->left);
    preorder(root->right);
}


int main()
{
    struct node *root=CreateTree();
    preorder(root);
    return 0;
}