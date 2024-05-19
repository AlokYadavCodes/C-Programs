#include <stdio.h>
#include<unistd.h> //for sleep function
#include <time.h>
int main(){
    time_t now;
    now=time(NULL);
    // time(&now);

    //assign the number of seconds since 1 Jan 1970 midnight
    printf("%ld",now); 
    
    // sleep(3);
    // printf("\nThis message is printed after 3 second of execution");
    // time_t threeSec=time(NULL);
    // printf("\n%ld",threeSec);

    // int timeDiff;
    // timeDiff=difftime(threeSec,now);  //first argument-second argument
    // printf("\nTime difference: %d",timeDiff);

    

    //A more readable format:
    char *nowString=ctime(&now);
    printf("\n%s",nowString);   //Sat May 18 20:53:49 2024

    //For control over individual parts:
    // struct tm *gmTime;   //gm=greenwich mean
    // gmTime=gmtime(&now);
    // printf("\n%d",gmTime->tm_hour);
    // printf("\n%d",gmTime->tm_mday);
    // printf("\n%d",gmTime->tm_year);  //year since 1900


    //for local time:
    printf("\nLocal Time: ");
    struct tm*localTime;
    localTime=localtime(&now);
    printf("\nYear: %d",localTime->tm_year);
    printf("\nMonth: %d",localTime->tm_mon);
    printf("\nWeek day: %d",localTime->tm_wday);
    printf("\nHour: %d",localTime->tm_hour);
    printf("\nisdst: %d",localTime->tm_isdst);

    //we can edit the values of the variables of the struct tm; for ex:
    localTime->tm_hour=localTime->tm_hour+1;
    printf("\nNew Hour: %d",localTime->tm_hour);

    //to convert the above structure to string format, we use asctime
    char *localString=asctime(localTime);
    printf("\nLocal time string:  %s",localString);

    //to convert this struct to the number of second, we use mktime
    time_t localSeconds=mktime(localTime);
    printf("Local Time in seconds: %ld",localSeconds);
    //useful while comparing times


    //to customize the string according to our preferred order, we use strftime:
    //syntax:
    // int len=strftime(stringName, stringMaxSize, "format specifiers", struct tm pointer);
    // it returns the lenght of the string(excluding null char); if fails to write string, it returns 0
    //link to format specifier: https://www.tutorialspoint.com/c_standard_library/c_function_strftime.htm
    char customizedString[100];
    strftime(customizedString,100,"%d %B %Y\t %I:%M:%S %p",localTime);
    printf("\nCustomized String: %s",customizedString);
    


    return 0;
}