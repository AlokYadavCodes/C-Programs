#include <stdio.h>
int main()
{
    int r,c;
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of columns:");
    scanf("%d",&c);
    int arr[r][c];
    printf("Enter the elements in Matrix:\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("Row %d , Column %d : ",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }
    int i,j;
    for(j=0;j<c;j++)
    {
        if(j%2==0)
        {
            for(i=r-1;i>=0;i--)
            printf("%d\t",arr[i][j]);
        }
        else
        {
            for(i=0;i<r;i++)
            printf("%d\t",arr[i][j]);

        }
    }
}