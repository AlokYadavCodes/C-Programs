#include<stdio.h>
int main()
{
    FILE *fptr;
    fptr=fopen("writing.txt","w");

    char text[]="This is meant to be written in the writing.txt file";

    fprintf(fptr,"This will be written in the text file\n");
    
    fprintf(fptr,"%s",text);
}