#include<stdio.h>
void rev(int array[],int si ,int ei)
{
    int temp; //si=starting index; ei=ending index
    while (si<ei)
    {
        temp=array[si];
        array[si]=array[ei];
        array[ei]=temp;
        si++;ei--;
    }
}
int main()
{
    int k;
    int arr[]={0,1,2,3,4,5,6,7,8},i;
    printf("Enter the index from where you want to rotate the array elements: ");
    scanf("%d",&k);
    k=k%8;
    rev(arr,0,8);
    rev(arr,0,k-1);
    rev(arr,k,8);
    
    for(i=0;i<9;i++)
    printf("%d,",arr[i]);
    
}