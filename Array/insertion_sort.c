#include<stdio.h>
void sort(int arr[],int size)
{
    for(int i=1;i<size;i++)
    {
        while(arr[i-1]>arr[i])
        {
            int temp=arr[i];
            arr[i]=arr[i-1];
            arr[i-1]=temp;
            i--;
            if(i==0)
            break;
        }
    }
}

int main()
{
    int size=10;
    int array[]={8,5,7,3,4,1,0,2,6,9};
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
    sort(array,size);
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);
    }
}