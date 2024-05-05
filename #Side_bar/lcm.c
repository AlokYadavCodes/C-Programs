#include<stdio.h>
int main()
{
    int num1,num2;
    printf("enter the two numbers: ");
    scanf("%d%d",&num1,&num2);
    int max=num1<num2?num2:num1;
    while(!(max%num1==0 && max%num2==0))
        max++;
    printf("LCM of %d and %d is %d",num1,num2,max);

    return 0;
}