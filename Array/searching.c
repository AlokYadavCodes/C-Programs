#include <stdio.h>
int main()
{
    int arr[]={2,4,66,78,84,45,73},num,i;
    printf ("Enter the number you want to search");
    scanf("%d",&num);
    for (i=0;i<7;i++)
    {
        if (arr[i]==num)
        {printf("Element founded successfully");
        printf("\n Found at index:%d",i);
        break;}
    }
    if (i==7)
    printf("Not Present in array");
    return 0;
}