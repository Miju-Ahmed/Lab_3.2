#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char)
{
    int a=10, b = 15;

    printf("Parent process pid is : %d\n", getpid());
    for(int i=0; i<3; i++){
        pid_t chldPid = fork();

        if(chldPid==-1){
            printf("Fork failed\n");
            exit(1);
        }else if(chldPid == 0){
            printf("Child process pid is : %d\n", getpid());
            printf("Summation : %d\n", a+b);
            printf("Abstractions : %d\n",a-b);
            printf("Multiplication : %d\n",a*b);
            printf("Division : %d\n",a/b);
        }else{
            printf("Its a parent process.\n");
        }
    }

    for(int i=0; i<3; i++){
        wait(NULL);
    }
}