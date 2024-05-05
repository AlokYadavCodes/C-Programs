#include <stdio.h>
int main()
{
    int y,t=0;
    printf("Enter the year");
    scanf("%d",&y);
    for (int i=1;i<y;i++)
    {
        if(((y%4==0) && (y%100!=0)) || ((y%4==0) && (y%100==0) && (y%400==0)))
        t++;
    }
    t=t%7;
    if (t==0)
    printf("Monday");
    else if (t==1)
    printf("Tuesday");
    else if (t==2)
    printf("Wednesday");
    else if (t==3)
    printf("Thrusday");
    else if (t==4)
    printf("Friday");
    else if (t==5)
    printf("Saturday");
    else
    printf("Sunday");
    return 0;

}