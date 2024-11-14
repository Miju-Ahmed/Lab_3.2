#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main(){
    pid_t p,s;
    printf("before fork\n");
    p = fork();
    if(p==0){
        printf("1 Child process PID : %d and parent pid : %d\n", getpid(), getppid());
    }
    else{
        s = fork();
        if(s==0){
            printf("2 s child pid is %d and its parent pid is %d\n",getpid(),getppid());
        }
        else{
            waitpid(p,NULL,0);
            printf("Im parent pid is %d\n first child p : %d\n second child s : %d\n", getpid(),p,s);
        }
    }
}