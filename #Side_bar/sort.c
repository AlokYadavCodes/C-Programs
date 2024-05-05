#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int select(int arr[], int i);
void selectionSort(int arr[], int n);
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[]={3,5,7,44,86,2,45,83,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    // ,n,T,i;
  
    // scanf("%d",&T);
    
    // while(T--){
        
    // scanf("%d",&n);
    
    // for(i=0;i<n;i++)
    //   scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    // }
    return 0;
}
// } Driver Code Ends


int select(int arr[], int i)
{
    int max=arr[i];
    int index=i,j;;
    for (j=i-1;j>=0;j--)
    {
        if(arr[j]>max)
        {
            max=arr[j];
            index=j;
        }
    }
    return index ;
}

void selectionSort(int arr[], int n)
{
    int i,j;
    for(i=n-1;i>0;i--)
    {
        j=select(arr,i);
        swap(&arr[i],&arr[j]);
    }
    
}