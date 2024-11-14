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
        for(int i=0; i<1; i--)
            printf("Child pid %d & MyPid %d\n",childPid,myPid);
    }
    else{
        myPid = getpid();
        for(int i=0; i<20000; i++)
            printf("Parent Pid %d & Mypid %d\n",childPid,myPid);
        exit(EXIT_SUCCESS);
    }
}

