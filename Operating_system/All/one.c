#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
void create_child_process(const char *child_name){
    pid_t p = fork();
    if(p==0){
        printf("Child %s pid is %d\n",child_name,getpid());
        sleep(5);
        exit(0);
    }
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    printf("Parent process pid %d\n",getpid());
    for(int i=2; i<argc; i++)
        create_child_process(argv[i]);
    for(int i=2; i<argc; i++)
        sleep(2);
    
}