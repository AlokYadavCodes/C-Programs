#include <stdio.h>
int main()
{
    int arr[]={7,9,5,3,4,8,2,6},max=arr[0],smax=arr[0];
    for(int i=1;i<8;i++)
    {
        if (max<arr[i])
        {
            smax=max;
            max=arr[i];
        }
        else if (arr[i]>smax && max!=arr[i])
        smax=arr[i];
    }
    printf("Max=%d\nSecond Max=%d",max,smax);
    return 0;
    
}