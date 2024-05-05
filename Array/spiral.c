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
    printf("\n");
    int i,j,maxrow=r-1,maxcol=c-1,minrow=0,mincol=0,count=0,tne=r*c;
    while(count<tne)
    {
        for(j=mincol;j<=maxcol;j++)
        
            {printf("%d\t",arr[minrow][j]);   
            count++;}
        minrow++;
        if (count==tne) break;

        for(i=minrow;i<=maxrow;i++)
        
            {printf("%d\t",arr[i][maxcol]);
            count++;}
        maxcol--;
        if (count==tne) break;

        for(j=maxcol;j>=mincol;j--)
        
            {printf("%d\t",arr[maxrow][j]); 
            count++;}  
        maxrow--;
        if (count==tne) break;
        
        for(i=maxrow;i>=minrow;i--)
        
            {printf("%d\t",arr[i][mincol]);
            count++;}
        mincol++;

    }
    return 0;
    
}