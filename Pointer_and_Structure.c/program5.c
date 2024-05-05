//passing structure pointer to a function: CALL BY REFERENCE
#include <stdio.h>
struct node 
{
    int data;
    float value;
};
void fun(struct node *m) //address of head is same as address of m; thus head and m has access to the same memory location.
{
    printf("Inside function: %d\n",m->data);
    m->data=30;
    printf("Inside function: %d\n",m->data);
}
int main()
{
    struct node n={10,20.20};
    struct node *head;
    head=&n;
    printf("Before Calling Function:%d\n",head->data);
    fun(head);
    printf("After Calling Function: %d\n",head->data);

    return 0;
}