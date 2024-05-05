#include <stdio.h>
int main()
{
    int num,n1,n2,n3,n4,n5,rev;
    printf("Enter a five digit number");
    scanf("%d",&num);
    n5=num%10; num=num/10;
    n4=num%10; num=num/10;
    n3=num%10; num=num/10;
    n2=num%10; num=num/10;
    n1=num%10; num=num/10;
    rev=n1+n2*10+n3*100+n4*1000+n5*10000;
    printf("Reversed No.=%d",rev);
    return 0;
}