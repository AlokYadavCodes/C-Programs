#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("\n------Welcome to the reading and writing into a file------\n");
    printf("\nEnter the file name: ");
    char fname[30];
    fgets(fname,30,stdin);
    fname[strcspn(fname,"\n")]='\0';
    FILE *fptr=fopen(fname,"w+");
    if(fptr==NULL){
        printf("\nError in opening file!");
        return 1;
    }
    while(1)
    {
        printf("\n1.Writing \n2.Reading \n3.Exit\nEnter you choice: ");
        int choice;
        char content[1000];
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            
            printf("\nEnter the content: ");
            getchar();
            fgets(content,1000,stdin);
            content[strcspn(content,"\n")]='\0';
            fputs(content,fptr);
            if(strlen(content)>0)
                fputs("\n",fptr);
            int result=fflush(fptr);
            if(result==0){
                printf("\nWritten Successfully!");
            }
            else{
                printf("\nError while writing!");
                fclose(fptr);
                fptr=NULL;
                return 2;
            }
            
            
            break;
    
            case 2:
            printf("\nThe content of the file is:\n");
            char ch='\0';
            fseek(fptr,0,SEEK_SET);
            while(ch!=EOF){
                ch=fgetc(fptr);
                printf("%c",ch);
            }

            // char file_content[100];    //to store the content of the file
            // fgets(file_content,100,fptr);   
            // printf("\n%s",file_content);
            break;

            case 3: 
            fclose(fptr);
            fptr=NULL;
            exit(0);
        }
    }
}