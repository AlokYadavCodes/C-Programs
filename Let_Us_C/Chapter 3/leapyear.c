#include <stdio.h>
int main()
{
    int y;
    printf("Enter the year");
    scanf("%d",&y);
    if((y%4==0 && y%100!=0) || (y%4==0 && y%100==0 && y%400==0))
    printf ("\n%d is a Leap Year",y);
    else 
    printf ("\n %d is not a Leap Year",y);
    return 0;
}