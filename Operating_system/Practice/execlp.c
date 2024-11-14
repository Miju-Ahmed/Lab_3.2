#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    char b[10];
    scanf("%s",b);
    pid_t c = fork();

    if(c==0){
        printf("Child process\n");
        execlp(b,b,NULL);
        printf("Not execute\n");
    }
    else{
        printf("Parent process\n");
    }
}