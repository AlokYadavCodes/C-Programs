#include <stdio.h>
int main()
{
    int r1,r2,c1,c2;
    printf("Enter the number of rows in Matrix 1:");
    scanf("%d",&r1);
    printf("Enter the number of columns in Matrix 1:");
    scanf("%d",&c1);
    printf("Enter the number of rows in Matrix 1:");
    scanf("%d",&r2);
    printf("Enter the number of columns in Matrix 1:");
    scanf("%d",&c2);
    int m1[r1][c1],m2[r2][c2],mul[r1][c2];

    if (c1!=r2)
    printf("Matrix Multiplication not possible");
    else
    { //user input
        printf("Enter the elements in Matrix 1:\n");
        for(int i=0;i<r1;i++)
        {
            for(int j=0;j<c1;j++)
            {
                printf("Row %d , Column %d : ",i+1,j+1);
                scanf("%d",&m1[i][j]);
            }
        }
        printf("\nEnter the elements in Matrix 2:\n");
        for(int i=0;i<r2;i++)
        {
            for(int j=0;j<c2;j++)
            {
                printf("Row %d , Column %d :" ,i+1,j+1);
                scanf("%d",&m2[i][j]);
            }
        }
        //multiplication
        for (int i=0;i<r1;i++)
        {
            for (int j=0;j<c2;j++)
            {   mul[i][j]=0;
               for (int k=0;k<c1/*r2*/;k++)
               { 
                    mul[i][j]+=m1[i][k]*m2[k][j];
               }
            }
        }
        //printing output
        printf("Multitplication Matrix :\n");
        for (int i=0;i<r1;i++)
        {
            for (int j=0;j<c2;j++)
            {
                printf("%d\t",mul[i][j]);
            } printf("\n");
        }
    }
    return 0;
}