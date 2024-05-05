#include <stdio.h>

int linearSearch(int arr[],int n,int key)
{
    for(int i=0;i<=n;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}
int main()
{
    int arr[]={3,4,5,6,2,1,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    int index=linearSearch(arr,n,key);
    if(index==-1)
        printf("Element not found");
    else
        printf("Element is found at index %d",index);
    
    return 0;
}