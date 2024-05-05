#include<stdio.h>
int main()
{
    int size;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    int arr[size];
    for (int i=0; i<size; i++)
    {
        printf("Enter the element number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int min=arr[0];
    for (int i=1; i<size-1; i++)
    {
        if (min>arr[i+1])
        min=arr[i+1];
    } 
    printf("Smallest element in the array is %d",min);
    return 0;
}