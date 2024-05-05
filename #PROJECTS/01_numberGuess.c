#include<stdio.h>
#include<stdlib.h>   //for rand() function
#include<time.h>     //for seeding rand() function

int main()
{
    printf("\n-----Welcome to the number guessing game-----\n");
    srand(time(NULL));
    int lowerlimit=1;
    int upperlimit=99;
    int num=rand()%upperlimit+lowerlimit;
    int count=0;
    int gNum;
    while(1)
    {
        count++;
        printf("\nPlease enter your guess between (0 to 100): ");
        scanf("%d",&gNum);
        if(gNum==num)
        {
            printf("\nCongratulation! You guessed the number in %d attempts.",count);
            break;
        }
        else if(gNum>num)
            printf("\nGuess a smaller number.");
        else if(gNum<num)
            printf("\nGuess a larger number.");
    }
}