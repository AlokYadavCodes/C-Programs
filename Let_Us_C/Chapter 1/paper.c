#include <stdio.h>
int main()
{
    int i=1189,j=841,t;
    for (int n=0; n<8; n++)
    {
        printf("A%d=%d*%d\n\n",n+1,i,j);
        t=i;
        i=j;
        j=t/2;
    }
    return 0;
}