#include<stdio.h>
#include<string.h>
void reverse(char str[])
{
    int lastIndex=strlen(str)-1;
    int i=0;
    while(i<lastIndex)
    {
        char temp=str[i];
        str[i]=str[lastIndex];
        str[lastIndex]=temp;
        i++;
        lastIndex--;
    }
}
int main()
{
    char name[20]="my name is alok";
    reverse(name);
    puts(name);
}