#include <stdio.h>
#include <time.h>
int main()
{
    time_t currentTime;
    time(&currentTime);  // assign seconds to currentTime
    printf("%d",currentTime);
    
    char *formattedTime=ctime(&currentTime);
    printf("%s",formattedTime);


    return 0;
}