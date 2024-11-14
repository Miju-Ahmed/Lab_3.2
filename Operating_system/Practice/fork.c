#include<unistd.h>
#include<stdio.h>

int main(){
    pid_t c = fork();
    if(c<0){
        printf("Fork Failed");
    }
    else if(c==0){
        printf("Child process\nPID: %d\nPPID: %d\n",getpid(), getppid());
    }
    else{
        printf("Parent process\nPID: %d\nc = %d\n", getpid(),c);
    }
}