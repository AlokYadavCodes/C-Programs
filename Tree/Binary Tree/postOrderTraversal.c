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

void postorder(struct node *root)
{
    if (root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}


int main()
{
    struct node *root=CreateTree();
    postorder(root);
    return 0;
}