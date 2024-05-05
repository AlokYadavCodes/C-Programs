#include<stdio.h>
int main()
{
    int sal;
    printf("Enter your salary");
    scanf("%d",&sal);
    sal=sal-0.4*sal-0.2*sal;
    printf("Your gross salary is %d",sal);
    return 0;
}