#include<stdio.h>
int main()
{
    char name[20];
    int max_size = sizeof(name) - 1;
    printf("Enter name: ");
    // gets(name);             //unsafe to use (depricated)
    fgets(name, max_size, stdin);  //recommended
    puts(name);     // to print the string without using any format specifier
}