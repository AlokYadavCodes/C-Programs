#include<stdio.h>
int main()
{
    int num,sum=0;
    printf("enter the number: ");
    scanf("%d",&num);
    while(num)
    {
        sum=sum*10+num%10;
        num/=10;
    }
    printf("reversed number is %d",sum);

    return 0;
}