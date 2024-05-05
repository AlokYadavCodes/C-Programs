#include <stdio.h>
int main()
{
    int x1,x2,x3,y1,y2,y3;
    printf ("Enter the values of (x1,y1)");
    scanf("%d%d",&x1,&y1);
    printf ("Enter the values of (x2,y2)");
    scanf("%d%d",&x2,&y2);
    printf ("Enter the values of (x3,y3)");
    scanf("%d%d",&x3,&y3);
    if ((y3-y2)/(x3-x2)==(y2-y1)/(x2-x1))
    printf("All these points lie on the same line");
    else
    printf("These points don't lie on the same line");
    return 0;
}