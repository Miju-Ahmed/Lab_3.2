#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main(){
    pid_t pid = fork();
    if(pid<0){
        fprintf(stderr,"Fork failed");
        return 1;
    }
    else if(pid==0){
        execlp("/bin/ls","ls",NULL);
    }
    else{
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}