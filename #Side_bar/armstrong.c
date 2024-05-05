#include<stdio.h>
#include<math.h>
int main()
{
    int num,sum=0,i=0;
    printf("enter a number: ");
    scanf("%d",&num);
    int num_temp=num;
    while(num_temp)
    {
        num_temp/=10;
        i++;
    }
    num_temp=num;
    while(num_temp)
    {
        sum+=pow(num_temp%10,i);
        num_temp/=10;
    } 
    if(sum==num)
        printf("Armstrong Number");
    else   
        printf("Not a armstrong number");

    return 0;
}