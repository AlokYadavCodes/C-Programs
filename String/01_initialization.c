#include<stdio.h>
int main()
{
    char str[]="Hello World!";
    char *name="Ramesh Yadav";
    puts(name);
    printf("%s",str);
    

    printf("\nEnter a string to print: ");
    scanf("%s",str);  //scanf stores only one word
    printf("%s",str);

}