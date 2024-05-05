//creation using array

#include <stdio.h>
#define MAX 20
int tree[MAX];

void root(char c)
{
    if (tree[0]!='\0')
        printf("Root element already exist.");
    else 
        tree[0]=c;
}

void left(char c, int parent)
{
    if (tree[parent]=='\0')
        printf("Can't add %c. Parent of %c doesn't exist.",c,c);
    else
        tree[2*parent+1]=c;
}
void right(char c, int parent)
{
    if (tree[parent]=='\0')
        printf("Can't add %c. Parent of %c doesn't exist.",c,c);
    else
        tree[2*parent+2]=c;
} 

void print()
{
    for(int i=0;i<MAX;i++)
    {
        if(tree[i]=='\0')
            printf("* ");
        else 
        printf("%c ",tree[i]);
    }
}

int main()
{
    root('A');
    left('B',0);
    right('C',0);
    left('D',1);
    right('E',2);

    print();

    return 0;
}