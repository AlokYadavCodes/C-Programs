#include<stdio.h>
#include<string.h>
int main()
{
    char source[]="Everyone";
    char target[20]="Hello";
    strcat(target,source);
    printf("%s",target);
}