#include <stdio.h>
#include <string.h>
int main()
{
    char source[30],target[30];
    printf("Enter the name of the source file : ");
    fgets(source,30,stdin);
    source[strcspn(source,"\n")]='\0';
    FILE *sfile=fopen(source,"r");
    if(sfile==NULL)
    {
        printf("Source file not found!");
        return 1;
    }
    printf("Enter the name of target file: ");
    fgets(target,30,stdin);
    target[strcspn(target,"\n")]='\0';
    FILE *tfile=fopen(target,"w");
    if(tfile==NULL)
    {
        printf("Target file not found!");
        return 1;
    }
    char ch;
    while(1)
    {
        ch=fgetc(sfile);
        if(ch==EOF) break;
        fputc(ch,tfile);
    }

    int status;
    status=fclose(sfile);  //returns 0 on closing the file
    status==0?printf("\nSource file closed successfullly"):printf("\nThere was a problem in closing the source file");
    status=fclose(tfile); 
    status==0?printf("\nTarget file closed successfullly"):printf("\nThere was a problem in closing the target file");
}