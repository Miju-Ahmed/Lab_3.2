#include<unistd.h>
#include<stdio.h>

int main(){
    pid_t pid = getpid();
    printf("%d\n",pid);
    printf("%d\n",getppid());
    return 0;
}