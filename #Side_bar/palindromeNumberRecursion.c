#include<stdio.h>
int reverse(int, int );
int main()
{
    printf("Enter the number: ");
    int num;
    scanf("%d",&num);
    printf("%d",reverse(num,0));

}

int reverse(int num, int rev)
{
    if(num==0)
        return rev;
    rev=rev*10+num%10;
    num/=10;
    reverse(num,rev);
}