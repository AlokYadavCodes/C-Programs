#include<stdio.h>

int removeElement(int nums[], int numsSize, int val) {
    int i=0,j,k=-1;
    while (i<numsSize)
    {
        if(nums[i]==val)
        {
            j=i+1;
            while(j<numsSize && nums[j]==val)
            {
                j++;
            }
            if(j<numsSize)
            {
                k++;
                nums[k]=nums[j];
                
            }
            i=j+1;
            
        }
        else
        {
            k++;
            nums[k]=nums[i];
            i++;
        }
    }
    return k+1;
}

int main()
{
    int arr[]={0,1,2,2,3,0,4,2},numsSize=sizeof(arr)/sizeof(arr[0]),val=2;
    int k=removeElement(arr,numsSize,val);
    for(int i=0;i<k;i++)
    {
        printf("%d ",arr[i]);
    }

return 0;
}