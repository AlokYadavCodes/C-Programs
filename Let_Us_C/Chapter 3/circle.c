#include <stdio.h>
#include<math.h>
int main()
{
    int x,y,r,x1,y1;
    printf("Enter the coordinates of the centre");
    scanf("%d%d",&x,&y);
    printf("Enter the radius of the circle");
    scanf("%d",&r);
    printf("Enter the coordinates of the point to be checked");
    scanf("%d%d",&x1,&y1);
    if (pow((x1-x),2)+pow((y1-y),2)<pow(r,2))
    printf("The point lie inside the circle");
    else if (pow((x1-x),2)+pow((y1-y),2)>pow(r,2))
    printf("The point do not lie inside the circle");
    else 
    printf("The point lie on the circle");
    return 0;
}