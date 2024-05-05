#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    struct node *left,*right;
    char data;
};

struct node* CreateTree();
struct node* addNode();
struct node* addright();

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

// void isFullBT(struct node *node)
// {
//     if(node==NULL || (node->left==NULL && node->right==NULL))
//     {
//         return;
//     }
//     if((node->left==NULL || node->right==NULL) && (node->left!=NULL || node->right!=NULL))
//     {
//         printf("Not a Full Binary Tree.");
//         exit(0);
//     }
//     else
//     {
//         isFullBT(node->left);
//         isFullBT(node->right);
//     }
// }

bool isFullBT(struct node *node)
{
    if(node==NULL || (node->left==NULL && node->right==NULL))
    {
        return true;
    }
    if(node->left && node->right)
    {
        return(isFullBT(node->left) && isFullBT(node->right));
    }
    return false; //If any of left or right is null and other has child
}

int main()
{
    struct node *root=CreateTree();
    
    if(isFullBT(root))
        printf("Full BT\n");
    else
        printf("Not Full BT\n");
    return 0;
}