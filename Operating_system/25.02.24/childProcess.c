#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    pid_t childP = fork();
    if(childP>0){
        printf("Parent Process %d\n",childP);
    }
    else{
        printf("Child Process %d\n",childP);
    }
    return 0;
}
