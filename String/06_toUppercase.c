#include<stdio.h>
#include<string.h>
#include<ctype.h>
void toUpper(char*);
int main()
{
    printf("Enter a string: ");
    char *str;
    fgets(str,30,stdin);
    str[0]='R';
    // toUpper(str);
    puts(str);

    return 0;
}

void toUpper(char *str)
{
    int i=0;
    while(str[i]!='\0')
    {
        str[i]=toupper(str[i]);
        i++;
    }
}