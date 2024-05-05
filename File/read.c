#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *fptr=fopen("myfile.txt","r");
    if(fptr==NULL){
        printf("\nError in opening file!");
        return 1;
    }
    char ch;
    while(ch!=EOF){
        ch=fgetc(fptr);
        printf("%c",ch);
    }
}