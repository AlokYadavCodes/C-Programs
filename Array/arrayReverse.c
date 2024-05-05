#include <stdio.h>
int main()
{
    int arr[]={1,2,4,3,6,5,9,7},rev[100],i;
    for(i=0;i<8;i++)
    {
        rev[7-i]=arr[i];
    }

    for(i=0;i<8;i++)
    {
        printf("%d,",rev[i]);
    }
    return 0;
}