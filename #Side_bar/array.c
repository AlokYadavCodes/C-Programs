#include<stdio.h>

void delElement(int arr[],int size,int element,int new_arr[],int *new__size)
{
    for(int i=0;i<size;i++){
        if(element==arr[i])
            break;
        else if(element!=arr[i] && i==size-1){
            printf("Element is not present in the array;");
            *new__size=0;
            return;
        }
    }
    int j=0;
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=element)
            new_arr[j++]=arr[i];
    }
    *new__size=j;
}

int main()
{
    // printf("Enter the size of the array :");
    int size=7;
    // scanf("%d",&size);
    int arr[]={2,3,5,1,9,5,7};
    // for(int i=0;i<size;i++)
    // {
    //     printf("Enter the value of element %d :",i+1);
    //     scanf("%d",&arr[i]);
    // }
    int new_array[100],newSize;
    delElement(arr,size,5,new_array,&newSize);
    for(int i=0;i<newSize;i++)
        printf("%d ",new_array[i]);
    
    return 0;
}