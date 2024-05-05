#include <stdio.h>
int main()
{
    int arr[]={1,3,3,2,3,3,2,3,3,1};
    int i=0,j=9;
    while (i<j)
    {
        if(arr[i]!=arr[j])
        {printf("Not a Palindrome");
        break;}
        i++;j--;
    }
    if(i=j)
    printf("Palindrome");
    return 0;
}

