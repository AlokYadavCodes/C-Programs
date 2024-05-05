#include<stdio.h>
#include<string.h>
int main()
{
    int dashborad[3][3]={{0,1,0},{1,0,0},{0,0,1}};
    for(int i=0; i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",dashborad[i][j]);
            // printf("i am j");
        }
        printf("\n");
        // printf("i am i");
    }
}