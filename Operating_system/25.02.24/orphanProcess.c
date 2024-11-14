#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t childPid = fork();
    pid_t myPid = getpid();
    if(childPid==0){
        printf("========Child Process======\n");
        myPid = getpid();
        for(int i=0; i> -1; i++){
            printf("Child pid %d\n",i);
        }
    }
    else{
        printf("=======Parent Process======\n");
        for(int i=0; i<50000; i++){
            printf("Parent pid %d\n",myPid);
        }
    }
    exit(0);
}



