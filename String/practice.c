#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    // printf("Enter your name: ");
    // char name[50];
    // int max_size=sizeof(name)-1;
    // fgets(name,max_size,stdin);
    // puts(name);




    // char day[20],month[20];
    // int year;
    // printf("Enter day: ");
    // fgets(day,19,stdin);
    // if(day[strlen(day)-1]=='\n')
    //     day[strlen(day)-1]='\0';
    // printf("Enter month name: ");
    // fgets(month,19,stdin);
    // if(month[strlen(month)-1]=='\n')
    //     month[strlen(month)-1]='\0';
    // printf("Enter year: ");
    // scanf("%d",&year);
    // printf("The date is: %s %s %d",day,month,year);



    // char *username="Ramesh01";
    // char *password="Ramesh@123";
    // char user[20]="alok123";
    // char pass[20];
    // printf("Enter username: ");
    // fgets(user,20,stdin);
    // if(user[strlen(user)-1]=='\n')
    //     user[strlen(user)-1]='\0';
    // printf("Enter password: ");
    // fgets(pass,20,stdin);
    // if(pass[strlen(pass)-1]=='\n')
    //     pass[strlen(pass)-1]='\0';
    // if(strcmp(user,username)==0 && strcmp(pass,password)==0)
    //     printf("Logged in Successfully!");
    // else 
    //     printf("Wrong password or username! Try again");





    // char str[30];
    // do
    // {
    //     printf("Enter any string: ");
    //     fgets(str,30,stdin);
    //     if(str[strlen(str)-1]=='\n')
    //     str[strlen(str)-1]='\0';
    //     if(!strcmp(str,"exit"))
    //         break;
    // }while(1);






    // int size;
    // printf("Enter the number of elements you want to store: ");
    // scanf("%d", &size);

    // int *arr= (int *)calloc(size, sizeof(int));
    // for(int i=0;i<size;i++)
    // {
    //     printf("Enter %d number: ",i+1);
    //     scanf("%d",&arr[i]);
    // }

    // for(int i=0;i<size+2;i++)
    // {
    //     printf("The %d number is: ",i+1);
    //     printf("%d  ",arr[i]);
    // }
    





    // int *arr= (int *)calloc(2, sizeof(int));
    // arr[0]=11;
    // arr[1]=22;

    // printf("\nCalloc Address is %p ",arr);
    // arr=(int *)realloc(arr,800*sizeof(int));
    // printf("\nRealloc address is %p",arr);
    
    // for(int i=0;i<3;i++)
    // {
    //     printf("\nThe %d number is: ",i+1);
    //     printf("%d  ",arr[i]);
    // }




    // printf("Welcome to the world of dynamic randoms\n");
    // long long int size=10;
    // int *arr=(int *)calloc(size,sizeof(int));
    // if(arr==NULL)
    // {
    //     printf("Memory Error!");
    //     return 1;
    // }
    // printf("%d",RAND_MAX);
    // printf("\nInitially:\n"); 
    // for(int i=0;i<size;i++)
    // {
    //     printf("%d ",arr[i]);
    // }

    // for(int i=0;i<size;i++)
    // {
    //     arr[i]=rand()%10;
    // }

    // printf("\nAfter randomization: \n");
    // for(int i=0;i<size;i++)
    // {
    //     printf("%d ",arr[i]);
    // }

    // int *shrinked=(int*)realloc(arr,size/2*sizeof(int));
    // if(shrinked==NULL)
    // {
    //     printf("Error");
    //     free(arr);
    //     arr=NULL;
    // }
    // arr=shrinked;
    // printf("\nAfter randomization: \n");
    // for(int i=0;i<size/2;i++)
    // {
    //     printf("%d ",arr[i]);
    // }

}