#include<stdio.h>
#include<stdlib.h>
int a=5;
int main()
{
    int *ptr1=malloc(sizeof(int));
    ptr1=&a;
    int *ptr2=malloc(sizeof(int));
    ptr2=&a;
    printf("%d ",*ptr1);

    printf("%d ",*ptr2);
    
    printf("%d ",a);

    
    return 0;
}