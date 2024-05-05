#include <stdio.h>
void sort(int arr[],int size)
{
    int i,j;
    for (i=0;i<size-1;i++)
    {
        int min_idx=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        if(min_idx!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min_idx];
            arr[min_idx]=temp;
        }
    }
}

void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
}

int main()
{
    int arr[]={3,5,4,1,7,9,2,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting:");
    print(arr,size);
    sort(arr,size);
    printf("After sorting:");
    print(arr,size);
}