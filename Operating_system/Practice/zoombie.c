#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
    pid_t c = fork();
    if(c==0){
        printf("Child process pid %d\n", getpid());
    }
    else{
        sleep(10);
        printf("Parent process %d\n",getpid());
    }
}