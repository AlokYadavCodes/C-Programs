#include <stdio.h>
#include <unistd.h>
#define SIZE 50
char bar[SIZE];
typedef struct{
    int id;
    int speed;
}Task;

int downloaded=0,failed=0;
void resetBar();
void runTask(Task task);




int main(){
    printf("\n\nDownload Menu:\n");
    Task task1={1,20};
    Task task2={2,10};
    Task task3={3,-2};
    Task task4={4,12};
    Task task5={5,0};
    
    runTask(task1);
    runTask(task2);
    runTask(task3);
    runTask(task4);
    runTask(task5);

    sleep(1);
    printf("\n%d task downloaded.",downloaded);
    if(failed){
        printf(" %d failed!\n\n",failed);
    }

    
}

void resetBar(){
    for(int i=0;i<=SIZE;i++){
        bar[i]=' ';
        if(i==SIZE){
            bar[i]='\0';
        }
    }
}


void runTask(Task task){
    resetBar();
    int progress=0;
    for(int i=0;i<SIZE;i=i+task.speed){
        for(int temp=i;temp<SIZE && temp<i+task.speed;temp++){
            bar[temp]='=';
            progress=((temp+1)*100)/SIZE;
        }
        printf("Task %d: ",task.id);
        printf("[");
        printf("%s",bar);
        printf("]");

        if(task.speed<=0){
            printf(" 0 %%");
            printf("\tCan't Download!");
            failed++;
            break;
        }
        if (progress==100){
            printf(" %d%%",progress );
            printf("\tDownload Successful!");
            downloaded++;
        }
        else{
            printf(" %d%%\r",progress );
        }
        
        sleep(1);
        
    }
    printf("\n");
}
