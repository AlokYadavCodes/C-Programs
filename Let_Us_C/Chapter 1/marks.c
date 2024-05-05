#include <stdio.h>
int main()
{
    int s1,s2,s3,s4,s5,sum;
    float per;
    printf("Enter the marks obtained in Subject 1\n");
    scanf("%d",&s1);
    printf("Enter the marks obtained in Subject 2\n");
    scanf("%d",&s2);
    printf("Enter the marks obtained in Subject 3\n");
    scanf("%d",&s3);
    printf("Enter the marks obtained in Subject 4\n");
    scanf("%d",&s4);
    printf("Enter the marks obtained in Subject 5\n");
    scanf("%d",&s5);
    if ((s1<=100) && (s2<=100) && (s3<=100) && (s4<=100) && (s5<=100)) //negative values still can be entered
    {
        sum=s1+s2+s3+s4+s5;
        per=sum/5;
        printf("Sum of marks is %d\n",sum);
        printf("Percentage obtained is %f",per);
        return 0;
    }
    else 
    printf("Please enter marks within range of 0 to 100"); 
}