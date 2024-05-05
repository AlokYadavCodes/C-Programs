#include<stdio.h>
int main()
{
    char name[30]="Alok yadav";  //mutable
    printf("\nArray before modification: %s",name);
    name[5]='Y';
    printf("\nArray after modification: %s",name);

    char *another_name="Ramesh yadav";
    printf("\nPointer before modification: %s",another_name);
    another_name[7]='Y';  //error (unexpected behaviour)
    printf("\nPointer after modification: %s",another_name);
}