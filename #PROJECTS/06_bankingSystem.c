#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUMBER_OF_CUSTOMERS 500
#define ACC_NO_STARTS_FROM 1000
#define NAME_MAX_LIMIT 20+1+1  //+1 for null character and another +1 for checking limit
#define PASSWORD_MAX_LIMIT 15+1+1
#define PASSWORD_MIN_LIMIT 8

typedef struct{
    char name[NAME_MAX_LIMIT];  
    int accNo;
    long long int contact;
    char* password;
    long long int balance;
} Customer;
Customer customers[MAX_NUMBER_OF_CUSTOMERS];
int customerCount=0;

void createAccount();
void login();
void depositMoney(int customerIndex);
void withdrawMoney(int customerIndex);
void checkBalance(int customerIndex);
void forgotAccountNo();
void forgotPassword();
int authenticate();
char* setPassword();
long long int setContact();
void clearScreen();
void displayGoBack();



int main(){
    while(1){
        clearScreen();
        printf("\n\n-------------------------------------------------------");
        printf("\n       *** Welcome to the India's No. 1 Bank ***");
        printf("\n-------------------------------------------------------");
        printf("\n1.Create New Account");
        printf("\n2.Login");
        printf("\n3.Forgot Account Number?");
        printf("\n4.Forgot Password?");
        printf("\n5.Exit ");

        printf("\n\nSelect option: ");
        int option;
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            createAccount();
            break;
        case 2:
            login();
            break;
        case 3:
            forgotAccountNo();
            break;
        case 4:
            forgotPassword();
            break;
        case 5:
            printf("\nThank you for using our services.");
            return 0;
        default:
            printf("\nInvalid option! Try again");
            break;
        }

    }
}

void createAccount(){
    clearScreen();
    Customer newCustomer;
    printf("\n--------- Create New Account ---------\n");
    printf("\nEnter your name: ");
    while(1){
        fflush(stdin);
        fgets(newCustomer.name,NAME_MAX_LIMIT,stdin);
        newCustomer.name[strcspn(newCustomer.name,"\n")]='\0';
        if(strcspn(newCustomer.name,"\0")==NAME_MAX_LIMIT-1){
            printf("\nName is too long! \nPlease enter your name (max %d characters): ",NAME_MAX_LIMIT-2);
        }
        else break;
    }
    
    newCustomer.accNo=ACC_NO_STARTS_FROM+customerCount;
    newCustomer.balance=0;
    while(1){
        printf("Enter your contact number: ");
        long long int contact=setContact();
        int isAlreadylinked=0;
        for(int i=0;i<customerCount;i++){
            if(contact==customers[i].contact){
                printf("\nError: Contact number is already linked to another account. Use a different contact number\n");
                isAlreadylinked=1;
            }
        }
        if(!isAlreadylinked){
            newCustomer.contact=contact;
            break;
        }
    }
    
    printf("Set a password to secure your account: ");
    newCustomer.password=setPassword();
    customers[customerCount++]=newCustomer;
    printf("\nDear %s, your account has been successfully created!",newCustomer.name);
    printf("\n\n---Account info---");
    printf("\nName: %s",newCustomer.name);
    printf("\nAccount Number: %lld",newCustomer.accNo);
    printf("\nContact Number: %lld",newCustomer.contact);
    displayGoBack();
}

void login(){
    int customerIndex=authenticate();
    if (customerIndex==-1) return;
    while(1){
        clearScreen();
        printf("\n\nWelcome back %s,\n --------LOGIN DASHBOARD--------\n ",customers[customerIndex].name);
        printf("\n1.Deposit Money");
        printf("\n2.Withdraw Money");
        printf("\n3.Check Balance ");
        printf("\n4.Logout");
        printf("\nSelect option: ");
        int option;
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            depositMoney(customerIndex);
            break;
        case 2:
            withdrawMoney(customerIndex);
            break;
        case 3:
            checkBalance(customerIndex);
            break;
        case 4:
            printf("\nLogged Out!");
            displayGoBack();
            return;
        
        default:
            printf("\nInvalid Option! Try again");
        }
    }
}

void depositMoney(int customerIndex){
    long long int amt;
    while(1){
        printf("\nEnter the amount to deposit: ");
        scanf("%lld",&amt);
        if(amt<=0){
            printf("\nAmmount can't be less than 1. Try again!");
        }
        else break;
    }
    customers[customerIndex].balance+=amt;
    printf("%lld has been deposited to your account! \nNew balance is: %lld ",amt,customers[customerIndex].balance);
    displayGoBack();
}

void withdrawMoney(int customerIndex){
    long long int amt;
    while(1){
        printf("\nEnter the amount to withdraw: ");
        scanf("%lld",&amt);
        if(amt<=0){
            printf("Withdrawl amount must be atleast 1. Try again!\n");
        }
        else break;
    }
    
    if(customers[customerIndex].balance<amt){
        printf("\nInsufficient Balance!");
        printf("\n\n1.Check Balance");
        printf("\n2.Try Again (default)");
        printf("\nEnter an option: ");
        int option;
        scanf("%d",&option);
        switch (option){
        case 1:
            checkBalance(customerIndex);
            return;
        default:
            withdrawMoney(customerIndex);
            return;
        }
    }
    customers[customerIndex].balance-=amt;
    printf("\n%lld has been debited from your account. \nRemaining balance is: %d ",amt,customers[customerIndex].balance);
    displayGoBack();
}

void checkBalance(int customerIndex){
    printf("\nYour account balance is: %lld ",customers[customerIndex].balance);
    displayGoBack();
}

void forgotAccountNo(){
    clearScreen();
    printf("\n--------- Retrieve Account Number ---------\n");
    long long int contact;
    printf("\nEnter contact number associated with your account: ");
    contact=setContact();
    int contactIndex=-1;
    for(int i=0;i<customerCount;i++){
        if(contact==customers[i].contact){
            contactIndex=i;
            break;
        }
    }
    if(contactIndex==-1){
        printf("%lld is not linked to any account.",contact);
        displayGoBack();
        return;
    }
    printf("\nEnter password: ");
    char *password=setPassword();
    if(strcmp(password,customers[contactIndex].password)!=0){
        printf("Incorrect Password!");
        displayGoBack();
        return;
    }
    int accNo=customers[contactIndex].accNo;
    printf("\nYour account number is: %d",accNo);
    displayGoBack();
}

void forgotPassword(){
    clearScreen();
    printf("\n--------- Retrieve Account Password ---------\n");
    printf("\nEnter your account number: ");
    long long int accNo;
    scanf("%lld",&accNo);
    printf("\nEnter contact number associated with the account: ");
    long long int contact;
    contact=setContact();
    int accNoIndex=-1;
    for(int i=0;i<customerCount;i++){
        if(accNo==customers[i].accNo){
            accNoIndex=i;
            break;
        }
    }
    if(accNoIndex==-1){
        printf("\nAccount number does not exists!");
        displayGoBack();
        return;
    }
    if(contact!=customers[accNoIndex].contact){
        printf("\nIncorrect contact number");
        displayGoBack();
        return;
    }
    printf("\nVerification Successful!\n");
    printf("\nEnter a new password: ");
    char *password=setPassword();
    customers[accNoIndex].password=password;
    printf("\nPassword changed successfully!");
    displayGoBack();
}

int authenticate(){
    fflush(stdin);
    int accNo;
    clearScreen();
    printf("\n--------- Login ---------\n");
    printf("\nEnter account number: ");
    scanf("%d",&accNo);
    printf("Enter password: ");
    char* password=setPassword();
    int accNoIndex=-1;
    for(int i=0;i<customerCount;i++){
        if(accNo==customers[i].accNo){
            accNoIndex=i;
        }
    }

    if(accNoIndex<0){
        printf("\nAccount number not found!");
        printf("\n1.Forgot Account Number?");
        printf("\n2.Try Again (default)");
        printf("\nEnter an option: ");
        int option;
        scanf("%d",&option);
        switch (option){
        case 1:
            forgotAccountNo();
            return -1;
        default:
            accNoIndex=authenticate();
            return accNoIndex;
        }
    }

    if(strcmp(password,customers[accNoIndex].password)!=0){
        printf("\nIncorrect Password!");
        printf("\n1.Forgot Password?");
        printf("\n2.Try Again (default)");
        printf("\nEnter an option: ");
        int option;
        scanf("%d",&option);
        switch (option){
        case 1:
            forgotPassword();
            return -1;
            break;
        default:
            return authenticate();
        }
    }
    return accNoIndex;
}

char* setPassword(){
    char *password=(char*)malloc(PASSWORD_MAX_LIMIT*sizeof(char));
    while(1){
        fflush(stdin);
        fgets(password,PASSWORD_MAX_LIMIT,stdin);
        password[strcspn(password,"\n")]='\0';
        //checking for minimum length
        if(strlen(password)<PASSWORD_MIN_LIMIT){
            printf("\nPassword is too short! \nPlease enter a password (min %d characters): ",PASSWORD_MIN_LIMIT);
        }
        else if(strcspn(password,"\0")==PASSWORD_MAX_LIMIT-1){
            printf("\nPassword is too long!\nPlease enter a password (max %d characters): ",PASSWORD_MAX_LIMIT-2);
        }
        else break;
    }    
    return password;
}

long long int setContact(){
        long long int contact;
        while(1){
            scanf("%lld",&contact);
            if(contact<1000000000 || contact>9999999999){
                printf("Please enter a 10 digit contact number: ");
            }
            else 
                return contact;
        }
}

void clearScreen(){
    #ifdef _WIN32  // for windows
        system("cls");
    #else  //for linux, mac
        system("clear");
    #endif
}

void displayGoBack(){
    printf("\n\n<-- Press ENTER to go back ");
    fflush(stdin);
    getchar();
}