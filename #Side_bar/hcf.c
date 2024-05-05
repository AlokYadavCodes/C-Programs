#include<stdio.h>
int main()
{
    int num1,num2;
    printf("enter the two numbers: ");
    scanf("%d%d",&num1,&num2);
    int i=num1<num2?num1:num2;
     
    while(!(num1%i==0 && num2%i==0))
        i--;

    printf("HCF of %d and %d is %d",num1,num2,i);

    return 0;
}