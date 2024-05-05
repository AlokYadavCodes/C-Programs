#include<stdio.h>

void isSorted(int arr[],int size)
{
    int inc=1,dec=1;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]<arr[i+1])
            dec=0;
        else if(arr[i]>arr[i+1])
            inc=0;
    }
    if(inc==1)
        printf("Increasing order");
    else if(dec==1)
        printf("Decreasing order");
    else
        printf("Not sorted");
}

int main()
{
    printf("Enter the size of the array :");
    int size;
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter the value of element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    isSorted(arr,size);
    
    return 0;
}