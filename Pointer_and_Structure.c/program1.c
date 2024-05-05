//passing element of a structure to a function without using pointer: CALL BY VALUE
#include <stdio.h>
struct node
{
    int data;
    float value;
};
void fun(int a)
{
    printf("Inside function: %d\n",a);
    a=30;
    printf("Inside function: %d\n",a);
}
int main()
{
    struct node n={10,20.20};
    printf("Before Calling Function: %d\n",n.data);
    fun(n.data);
    printf("After Calling Function: %d\n",n.data);

    return 0;
}