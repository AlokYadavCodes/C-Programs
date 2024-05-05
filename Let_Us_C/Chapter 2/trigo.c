#include <stdio.h>
#include<math.h>
int main()
{
    float a;
    printf("Enter the angle (a) in radian");
    scanf("%f",&a);
    printf("sin a=%f\n",sin(a));
    printf("cos a=%f\n",cos(a));
    printf("tan a=%f\n",tan(a));
    printf("cosec a=%f\n",1/sin(a));
    printf("sec a=%f\n",1/cos(a));
    printf("cot a=%f\n",1/tan(a));
    return 0;

}