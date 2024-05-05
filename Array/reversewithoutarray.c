#include <stdio.h>
int main()
{
    int arr[]={1,2,4,3,6,5,9,7},temp,i;
    for(i=0;i<8/2;i++)
    {
        temp=arr[7-i];
        arr[7-i]=arr[i];
        arr[i]=temp;
    }    
    printf("After reversing :\n");
    for (i=0;i<8;i++)
    {
        printf("%d,",arr[i]);
    }
}