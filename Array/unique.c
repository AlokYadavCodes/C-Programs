//all elements are repeated except one, find that;
#include <stdio.h>
int main()
{
    int arr[]={3,5,6,7,8,5,3,9,2,4,8,7,6,4,2},i,j; //unique element is 9
    for (i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            if(arr[i]==arr[j] && i!=j)
                break;
        }
        if(j==15)
        {printf("\nUnique element is %d",arr[i]);
        break;}
    }
    if (i==15)
        printf("No unique element");
    return 0;
}