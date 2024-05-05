#include<stdio.h>
int main()
{
    FILE *file_pointer;

    file_pointer=fopen("sample.txt","r");   //opening file
    if(file_pointer==NULL)                  //checking if the file was opened or not
    {
        printf("There was a problem in opening the file.");
        return 1;
    }

    // printf("\n%p\n",file_pointer);

    // //reading file (single line)
    // char file_content[100];    //to store the content of the file
    // fgets(file_content,100,file_pointer);   
    // printf("\n%s",file_content);

    //reading file(entire file)
    char ch;
    while (ch!=EOF)
    {
        ch=fgetc(file_pointer);
        printf("%c",ch);
    }
    

    //closing file
    int result=fclose(file_pointer);    // returns 0 on closing the file
    if(result==0)
    {
        printf("\nFile is closed");
        file_pointer=NULL;
    }
    else
    {
        printf("\nFile was not closed properly.");
        return 1;
    }

}