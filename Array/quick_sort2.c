//Upper bound as pivot

#include<stdio.h>

void swap(int arr[],int a,int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

void quick_sort(int arr[],int lb,int ub)
{
    if(lb>=ub)
    {
        return;
    }
    int pivot=ub;
    int start=lb,end=ub;
    while(start<end)
    {
        while(arr[pivot]>arr[start])
        start++;

        while(arr[pivot]<=arr[end])
        end--;

        if(start<end)
        {
            swap(arr,start,end);
        }
        else
            swap(arr,pivot,start);
    }
    
    quick_sort(arr,lb,start-1);
    quick_sort(arr,start+1,ub);
    
}

int main()
{
    int size=7;
    int arr[]={4,2,8,3,1,0,5};
    printf("\nUnsorted array:");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);

    quick_sort(arr,0,size-1);
    printf("\nSorted array:  ");
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    
    return 0;
}