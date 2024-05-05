#include<stdio.h>
int main()
{
    int arr[][3]={1,2,3,4,5,6,7,8,9},brr[3][3];
    int i,j;
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
    
            brr[i][j]=arr[2-j][i];
          //  arr[j][i]=temp;
        }
    } 
    for (i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",brr[i][j]); 
            printf("\n");
    }
    return 0;
}