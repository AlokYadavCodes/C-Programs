//Lower bound as pivot 

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
    int pivot=lb;
    int start=lb,end=ub;
    while(start<end)
    {
        while(arr[pivot]>=arr[start])
        start++;

        while(arr[pivot]<arr[end]) 
        end--;  

        if(start<end)
        {
            swap(arr,start,end);
        }
        else
            swap(arr,pivot,end);
    } 
    quick_sort(arr,lb,end-1);
    quick_sort(arr,end+1,ub);  
}

void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int size=7;
    int arr[]={5,4,6,0,7,2,8};
    printf("\nUnsorted array:");
    print(arr,size);
    quick_sort(arr,0,size-1);
    printf("\nSorted array:  ");
    print(arr,size);
    return 0;
}