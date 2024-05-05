#include<stdio.h>
int main()
{
    int c,d;
    printf("Enter the values of C and D respectively");
    scanf("%d%d",&c,&d);
    c=c+d;
    d=c-d;
    c=c-d;
    printf("After interchanging C=%d and D=%d",c,d);
    return 0;
}