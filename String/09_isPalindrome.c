#include<stdio.h>
#include<string.h>
int isPalindrome(char str[])
{
    int lastIndex=strlen(str)-1;
    for(int i=0;i<lastIndex;i++)
    {
        if(str[i]!=str[lastIndex-i])
            return 1;
    }
    return 0;
    
}
int main()
{
    printf("Enter a string: ");
    char str[30];
    fgets(str,30,stdin);
    if(str[strlen(str)-1]=='\n')
        str[strlen(str)-1]='\0';
    int i=isPalindrome(str);
    if(i==0)
        printf("Palindrome");
    else 
        printf("Not a Palindrome");
}