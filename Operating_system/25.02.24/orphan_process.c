#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t childPid,myPid;
    childPid = fork();
    if(childPid<0){
        printf("Child Process was not created\n");
        exit(EXIT_FAILURE);
    }
    else if(childPid==0){
        myPid = getpid();
        printf("Child pid %d & MyPid %d\n",childPid,myPid);
    }
    else{
        myPid = getpid();
        printf("Parent Pid %d & Mypid %d\n",childPid,myPid);
        exit(EXIT_SUCCESS);
    }
}
