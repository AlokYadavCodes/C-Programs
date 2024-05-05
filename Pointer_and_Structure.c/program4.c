//passing whole structure to a function using pointer: CALL BY REFERENCE
#include <stdio.h>
struct node 
{
    int data;
    float value;
};
void fun(struct node *m)
{
    printf("Inside function: %d\n",m->data);
    m->data=30;
    printf("Inside function: %d\n",m->data);
}
int main()
{
    struct node n={10,20.20};
    printf("Before Calling Function: %d\n",n.data);
    fun(&n);
    printf("After Calling Function: %d\n",n.data);

    return 0;
}