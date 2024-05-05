#include<stdio.h>

int binarySearch(int arr[],int size,int key)
{
    int start,end,middle;
    start=0,end=size-1;
    while(start<=end)
    {
        middle=(start+end)/2;
        if(arr[middle]==key)
            return middle;
        if(key<arr[middle])
            end=middle-1;
        if(key>arr[middle])
            start=middle+1;
    }
    return -1; 
}

int main()
{          //  0 1 2 3 4 5 6
    int arr[]={2,3,4,5,6,7,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=6;
    int result=binarySearch(arr,size,key);
    if(result==-1)
        printf("Element not found");
    else
        printf("Index isfound at index %d",result);

    return 0;
}