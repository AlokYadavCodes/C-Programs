#include <stdio.h>
void sort(int arr[],int size)
{
    int i,j;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j+1]<arr[j])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
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
    printf("\n");
    printf("After sorting:");
    print(arr,size);

    return 0;
}