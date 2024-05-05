#include <stdio.h>
int main()
{
    int cp,sp,p,l;
    printf("Enter the cost price");
    scanf("%d",&cp);
    printf("Enter the selling price");
    scanf("%d",&sp);
    if (cp<sp)
    {
        p=sp-cp;
        printf("Profit=%d",p);
    }
    else
    {
        l=cp-sp;
        printf("Loss=%d",l);
    }
    return 0;
}