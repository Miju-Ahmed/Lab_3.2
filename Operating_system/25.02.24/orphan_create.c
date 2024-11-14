#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
    pid_t childP = fork();

    if(childP<0){
        printf("Child is not created.\n");
        exit(EXIT_FAILURE);
    }
    else if(childP>0){
        printf("Parent process of pid : %d\n",getpid());
        sleep(1);
        printf("Parent process existing\n");
        exit(0);//For destroying this Parent process
    }
    else{
        printf("Child process with pid : %d\n",getpid());
        sleep(5);
        printf("Child process existing\n");
        exit(EXIT_SUCCESS);
    }
    return 0;
}


