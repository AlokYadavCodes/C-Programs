#include <stdio.h>
int main()
{
    int num,sum=0;
    printf("Enter a number: ");
    scanf("%d",&num);
    int num_temp=num;
    while(num_temp)
    {
        sum=sum*10+num_temp%10;
        num_temp/=10;
    }
 
    sum==num?printf("Palindrome Number"):printf("Not a palindrome Number");

    return 0;
}