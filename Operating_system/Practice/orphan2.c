#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t c = fork();
    if(c==0){
        sleep(2);
        printf("my pid is %d\n",getpid());
        printf("my parent pid is %d\n",getppid());
    }
    else{
        printf("parent pid is %d\n",getpid());
    }
}

//then is will show the systemd 2296 pid number.