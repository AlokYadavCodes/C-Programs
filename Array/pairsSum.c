#include <stdio.h>
int main()
{
    int size,i,j,num,count=0;
    printf("Enter the size of the array :");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        printf("Enter the element number %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the number: ");
    scanf("%d",&num);
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i]+arr[j]==num)
           { count++;
            printf("(%d,%d)",arr[i],arr[j]);}
        }
    }
    printf("Number of pairs is: %d",count);
    return 0;
    
}
