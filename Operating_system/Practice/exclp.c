#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>


int main(){
    pid_t c = fork();

    if(c==0){
        printf("Child Process\n");
        execlp("./process","process",NULL);
        printf("Can't go there\n");
    }
    else{
        wait(NULL);
        printf("Parent process");
    }
}