#include<stdio.h>
long long factorial(long long);
int main()
{
    long long num;
    printf("Enter the number: ");
    scanf("%lld",&num);
    printf("%lld",factorial(num));

}

long long factorial(long long num)
{
    if(num==0)
        return 1;
    else
        return num*factorial(num-1);
}