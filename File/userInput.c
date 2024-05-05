#include <stdio.h>
#include<string.h>
int main()
{
    printf("Enter the file name: ");
    char fname[20];
    fgets(fname,20,stdin);
    fname[strcspn(fname,"\n")]='\0';
    FILE *fptr=fopen(fname,"a+");
    if(fptr==NULL){
        printf("\nError in opening file!");
        return 1;
    }
    printf("Enter the content to put on the file: ");
    char content[1000];
    do
    {
        fgets(content,1000,stdin);
        content[strcspn(content,"\n")]='\0';
        int result;
        result=fputs(content,fptr);
        if(strlen(content)>0)
            fputs("\n",fptr);
        if(result==EOF){
            printf("\nError in writing to the  file.");
            return 2;
        }
    } while(strlen(content)>1);
    printf("\nSuccessfully written.");
    fclose(fptr);
    fptr=NULL;
}
