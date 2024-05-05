#include <stdio.h>
int main()
{
    float dis;
    printf ("Enter the distance in KM");
    scanf("%f",&dis);
    printf("Distance in meters: %0.2f\n",dis*1000);
    printf("Distance in feet: %0.2f\n",dis*3280.84);
    printf("Distance in inches: %0.2f\n",dis*39370.08);
    printf("Distance in centimeters: %0.2f\n",dis*1e5);
    return 0;

}