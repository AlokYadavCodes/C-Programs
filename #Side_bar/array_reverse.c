#include<stdio.h>
void reverse(int*,int);
void print(int *,int);
int main()
{
    int arr[]={2,3,5,1,9,5,4,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    reverse(arr,size);
    print(arr,size);

}

void reverse(int arr[],int size)
{
    for(int i=0;i<size/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
}
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}