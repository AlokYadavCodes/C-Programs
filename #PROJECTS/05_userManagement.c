#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#define CREDENTIALS_LENGTH 100
#define MAX_USERS 150
void registerUser();
int loginUser();
void setUserAndPass(char *username,char *password);
typedef struct{
    char username[CREDENTIALS_LENGTH];
    char password[CREDENTIALS_LENGTH];
} user;
user users[MAX_USERS];
int noOfUsers=0;

int main(){
    while(1){
        printf("\n1.Register");
        printf("\n2.Login");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            registerUser();
            break;

        case 2:
            int userIndex=loginUser();
            if(userIndex>=0){
                printf("\nLogged in successfully! Welcome %s",users[userIndex].username);
            }
            else{
                printf("\nInvalid username or password!");
            }
            break;
                
        case 3:
            printf("\nExiting...");
            exit(1);
    
        default:
            printf("\nEnter a valid choice!\n");
        }
    }
}

void registerUser(){
    if(noOfUsers==MAX_USERS){
        printf("\nSeats for registration is already filled!\n");
        return;
    }
    user newUser;
    setUserAndPass(newUser.username,newUser.password);
    users[noOfUsers++]=newUser;
    printf("\nRegistered Successfully!");
}

int loginUser(){
    char usernameInput[CREDENTIALS_LENGTH],passwordInput[CREDENTIALS_LENGTH];
    setUserAndPass(usernameInput,passwordInput);
    for(int i=0;i<noOfUsers;i++){
        if(strcmp(users[i].username,usernameInput)==0 && strcmp(users[i].password,passwordInput)==0){
            return i;
        }
    }
    return -1;
}

void setUserAndPass(char *username, char *password){
    printf("\nEnter your username: ");
    fflush(stdin);
    fgets(username,CREDENTIALS_LENGTH,stdin);
    username[strcspn(username,"\n")]='\0';
    printf("\nEnter your password: ");

    // struct termios oldProperties,newProperties;
    // tcgetattr(STDIN_FILENO,&oldProperties);
    // newProperties=oldProperties;
    // newProperties.c_lflag=~(ECHO | ICANON);
    // // tcsetattr(STDIN_FILENO,TCSANOW,&newProperties);
    // fgets(password,CREDENTIALS_LENGTH,stdin);
    // password[strcspn(password,"\n")]='\0';
    // // tcsetattr(STDIN_FILENO,TCSANOW,&oldProperties);
}