#include <stdio.h>
int main()
{
    int l,b,r;
    float arR,pR,arC,pC;
    printf("Enter the length and breadth of rectangle\n");
    scanf("%d%d",&l,&b);
    arR=l*b; 
    pR=2*l*b;
    printf("Area of Rectangle=%f\n Perimeter=%f\n",arR,pR);
    printf("Enter the readius of Circle\n");
    scanf("%d",&r);
    arC=3.14*r*r;
    pC=2*3.14*r;
    printf("Area of Circle=%f\n Perimeter=%f",arC,pC);
    return 0;
}