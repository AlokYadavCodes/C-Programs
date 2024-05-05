#include <stdio.h>

int index_sequential(int arr[],int n,int key)
{
    int indices[n],elements[n],GN=3,idx=0,i;
    for(i=0; i<n;i+=GN)
    {
        indices[idx]=i;
        elements[idx]=arr[i];
        idx++;
    }
    if(key<elements[0])
        return -1;
    for(i=0;i<idx;i++)
    {
        if(key>elements[i])
            continue;
        else
        {
            if(key==elements[i])
                return indices[i];
            int start=indices[i]-GN+1,end=indices[i]-1;
            for(i=start;i<=end;i++)
            {
                if(arr[i]==key)
                    return i;
            }
            return -1;
        }
        
    }   
}
int main()
{
    int arr[]={3,4,5,6,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int key=9;
    int index=index_sequential(arr,n,key);
    if(index==-1)
        printf("Element not found");
    else
        printf("Element is found at index %d",index);
    
    return 0;
}