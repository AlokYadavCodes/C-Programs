#include <stdio.h>
int main()
{
    int amt,r1,r2,r5,r10,r50,r100;
    printf ("Enter the Amount");
    scanf("%d",&amt);
    r100=amt/100; amt=amt%100;
    r50=amt/50; amt=amt%50;
    r10=amt/10; amt=amt%10;
    r5=amt/5; amt=amt%5;
    r2=amt/2; amt=amt%2;
    r1=amt;
    int sum=r1+r2+r5+r10+r50+r100;
    printf("Minimum Notes Required=%d",sum);
    return 0;
}