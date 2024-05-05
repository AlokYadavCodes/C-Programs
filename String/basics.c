#include<stdio.h>
int main()
{
    printf("%s","1.hello everyone");
    printf("\n");

    // printf("%s",'2.hello everyone');     //this will give error because single inverted commas '' are used with characters only not strings
    // printf("\n");

    printf("%s","2.this is \
    very good");
    printf("\n");

    printf("%s","3.this is "
    "very good");
    printf("\n");

    char name[]="Ramesh";
    printf("4.%15.3s",name);
    
    printf(" %c",name[0]);
    printf("Ji");
    printf("\n");

    int i=0;
    while(name[i]!='\0')
    {
        printf("%c",name[i]);
        i++;
    }
    printf("\n");

    // char newname[30];
    // scanf("%s",newname);  //& is not necessary to scan string (because c passes base address while passing a array name)
    // printf("%s",newname); //only one word can be read by scanf function

    // char fullname[30];
    // gets(fullname);         //it can read multiple words
    // printf("Your name is:");
    // puts(fullname); 

    char yourname[30];
    printf("Enter your name:");
    scanf("%[^\n]s",yourname);  //it will read untill it encounters \n i.e. untill Enter key is pressed
    printf("%s",yourname);

    return 0;
}