#include<stdio.h>
int fibonacci(int);
int main()
{
    printf("Enter the number of terms: ");
    int pos;
    scanf("%d",&pos);

    for(int i=1;i<=pos;i++)
        printf("%d ",fibonacci(i));

    return 0;
}

int fibonacci (int pos)
{
    if(pos<=2)
        return pos-1;
    else
        return fibonacci (pos-1) +fibonacci(pos-2);
}