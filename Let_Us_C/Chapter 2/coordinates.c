#include <stdio.h>
#include<math.h>
int main()
{
    float x,y,r,t;
    printf("Enter the X and Y coordinates respectively");
    scanf("%f%f",&x,&y);
    r=sqrt(x*x+y*y);
    t=atan(x/y);
    printf("Coordinates in Polar form: (r,t)=(%f,%f)",r,t);
    return 0;
    
}