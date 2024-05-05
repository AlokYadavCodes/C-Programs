#include<stdio.h>
int main()
{
// *
// *       *
// *       *       *
// *       *       *       *
// *       *       *       *       *
    for(int i=0;i<5;i++)
    {
        for(int j=0; j<i+1;j++)
        {
            printf("*\t");
        }
        printf("\n");
    }

printf("\n\n");

// *       *       *       *       *
// *       *       *       *
// *       *       *
// *       *
// *
    for(int i=5;i>0;i--)
    {
        for(int j=i; j>0;j--)
        {
            printf("*\t");
        }
        printf("\n");
    }


printf("\n\n");
//                                 *
//                         *       *
//                 *       *       *
//         *       *       *       *
// *       *       *       *       *

    for(int i=0;i<5;i++)
    {
        for(int k=5;k>i+1;k--)
        {
            printf("\t");
        }
        for(int j=0;j<i+1;j++)
        {
            printf("*\t");
        }
        printf("\n");
    }

    return 0;

}