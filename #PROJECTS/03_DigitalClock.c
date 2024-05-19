#include <stdio.h>
#include <time.h>
#include <unistd.h> //for sleep function
#include <stdlib.h>

int getChoice();
void getTime(char[],int choice);
void getDate(char[]);
void clearScreen();

int main(){
        int choice=getChoice();
        char timeString[100],dateString[100];
        while(1){
        clearScreen();
        getTime(timeString,choice);
        getDate(dateString);
        
        printf("\nCurrent Time: ");
        printf("%s",timeString);
        printf("\nDate: ");
        printf("%s\n",dateString);
        sleep(1);
    }
}


int getChoice(){
    printf("\nChoose the time format: ");
    printf("\n1. 24 Hour Format");
    printf("\n2. 12 Hour Format (default)");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d",&choice);
    return choice;
}

void getTime(char timeString[],int choice){
    time_t now=time(NULL);
    struct tm *currentTime=localtime(&now);
    char format12[100],format24[100];
    if(choice==1){
        strftime(timeString,100,"%H:%M:%S",currentTime);
    }
    else{
        strftime(timeString,100,"%I:%M:%S %p",currentTime);
    }
}

void getDate(char dateString[]){
    time_t now=time(NULL);
    struct tm *currentTime=localtime(&now);
    char date[100];
    strftime(dateString,50,"%A %B %d %Y",currentTime);
}

void clearScreen(){
    // #define CLEAR_SCREEN "\e[1A\e[0;H\e[J"   //escape sequence
    // printf(CLEAR_SCREEN);
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}