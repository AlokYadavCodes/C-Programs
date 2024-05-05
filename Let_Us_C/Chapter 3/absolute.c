#include <stdio.h>
int main()
{
    int num;
    printf("Enter any Number ");
    scanf("%d",&num);
    if (num<0)
    num=-num;
    printf("Absolute value of enteres number is %d",num);
    return 0;

}