#include<stdio.h>
int main()
{
    printf("Fibonacci Series : \n");
    int a=0,b=1,c=0;
    printf("%d %d ",a,b);
    while(c<300)
    {
        c=a+b;
        printf("%d ",c);
        a=b;
        b=c;
    }
    return 0;
}