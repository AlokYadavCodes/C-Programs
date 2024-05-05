#include <stdio.h>
int main()
{
    int num,n1,n2,n3,n4,n5,sum;
    printf("Enter a five digit number");
    scanf("%d",&num);
    n5=num%10; num=num/10;
    n4=num%10; num=num/10;
    n3=num%10; num=num/10;
    n2=num%10; num=num/10;
    n1=num%10; num=num/10;
    sum=n1+n2+n3+n4+n5;
    printf("Sum of digits =%d",sum);
    return 0;
}