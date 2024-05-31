#include<stdio.h>
#include<string.h>
int main(){
    int index=-1;
    index=strcspn("hello","kfs");
    // strcspn: Think of it as finding the length of the prefix in the first string that doesn't contain any characters from the second string.
    printf("%d",index);
}