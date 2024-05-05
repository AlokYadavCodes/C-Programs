#include<stdio.h>
int isPalindrome(int*,int);
int main()
{
    int arr[]={2,3,5,1,2,5,3,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int flag=isPalindrome(arr,size);
    flag==1?printf("palindrome"):printf("not palindrome");
    

}

int isPalindrome(int arr[],int size)
{
    for(int i=0;i<size/2;i++)
    {
        if(arr[i]!=arr[size-1-i])
            return 0;
    }
    return 1;
}
