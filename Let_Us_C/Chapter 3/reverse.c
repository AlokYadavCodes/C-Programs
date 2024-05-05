#include <stdio.h>
int main()
{
    int num,n1,n2,n3,n4,n5,rev;
    printf("Enter a five digit tempber");
    scanf("%d",&num);
    int temp=num;
    n5=temp%10; temp=temp/10;
    n4=temp%10; temp=temp/10;
    n3=temp%10; temp=temp/10;
    n2=temp%10; temp=temp/10;
    n1=temp%10; temp=temp/10;
    rev=n1+n2*10+n3*100+n4*1000+n5*10000;
    printf("Reversed No.=%d\n",rev);
    if (num==rev)
    printf("Original and Reversed tempbers are equal");
    else 
    printf("Original and Reversed tempbers are not equal");
    return 0;
}