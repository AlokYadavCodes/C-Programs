#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    int choice;
    double num1,num2;
    double result;
    while(1)
    {
        printf("\n\n---------------------------------");
        printf("\nWelcome to the Calculator Program");

        printf("\n\nChoose one of the following operations:");
        printf("\n1. Add \n2. Subtract \n3. Multiplication \n4. Division \n5. Modulus \n6. Power \n7. Exit");
        printf("\nNow enter your choice: ");
        scanf("%d",&choice);
        if (choice==7){
            printf("\nThank you for using this calculator! Have a great day.\n");
            exit(0);
        }
        if (choice>7){
            printf("\nInvalid Choice!\n");
            continue;
        }
        printf("\nEnter the first number: ");
        scanf("%lf",&num1);
        printf("\nEnter the second number: ");
        scanf("%lf",&num2);
        switch (choice)
        {
        case 1:
        result=num1+num2;
        break;

        case 2:
        result=num1-num2;
        break;

        case 3:
        result=num1*num2;
        break;

        case 4:
        if(num2==0){
            printf("\nInvalid inputs!");
            result=NAN;
            break;
        }
        result=num1/num2;
        break;

        case 5:
        if(num2==0){
            printf("\nInvalid inputs!");
            result=NAN;
            break;
        }
        result=(int)num1%(int)num2;
        break;

        case 6:
        result=pow(num1,num2);
        break;        
        }
        
        //we can't compare NAN with any number i.e: if(result==NAN) will not work (always false). We have to use isnan() function
        if(!isnan(result)){          //isnan function provided by math.h
            printf("\nResult of operation is: %0.2lf ",result);
        }
    }
}