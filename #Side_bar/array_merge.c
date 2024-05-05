#include<stdio.h>
void merge(int*, int, int*, int, int*, int*);
int main()
{   
    int arr1[]={1,3,5,8,9};   //already sorted
    int arr2[]={1,4,6,23,25,40}; //already sorted
    int arr3[100],size3;
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    merge(arr1,size1,arr2,size2,arr3,&size3);
    for(int i=0;i<size3;i++)
        printf("%d ",arr3[i]);
    
}

void merge(int arr1[],int size1,int arr2[],int size2,int arr3[],int *size3)
{
    int i=0,j=0,k=0;
    int repeat=0;
    while(k<size1+size2-repeat)
    {
        if(i!=size1 && j!=size2 && arr1[i]==arr2[j])
        {
            arr3[k++]=arr1[i++];
            j++; 
            repeat++;
        }
        else if(j==size2 || i!=size1 && arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];

        else
            arr3[k++]=arr2[j++];
    }

    *size3=k;
}