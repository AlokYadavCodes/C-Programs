#include<stdio.h>
int main()
{
    int num,sum=0;
    printf("enter the number");
    scanf("%d",&num);
    while (num)
    {
        sum+=num%10;
        num=num/10;
    }
    printf("sum is %d",sum);
    
    return 0;
}