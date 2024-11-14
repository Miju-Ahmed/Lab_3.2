#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<errno.h>

int main(){
    pid_t pid = getpid();
    printf("Initial priority of process %d is %d\n", pid, getpriority(PRIO_PROCESS, pid));
    setpriority(PRIO_PROCESS,pid,10);
    printf("Updated priority of process %d is %d\n",pid,getpriority(PRIO_PROCESS,pid));
    return 0;
}