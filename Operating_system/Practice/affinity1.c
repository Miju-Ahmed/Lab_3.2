#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<sched.h>

void set_cpu(pid_t pid, int cpu){
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu,&mask);
    if(sched_setaffinity(pid,sizeof(mask),&mask)==-1)
        printf("Can't set affinity\n");
    else
        printf("Set affinity\n");
}

void get_cpu(pid_t pid){
    cpu_set_t mask;
    CPU_ZERO(&mask);
    if(sched_getaffinity(pid,sizeof(mask),&mask)==-1)
        printf("Fail sched_getaffinity()\n");
    else{
        printf("Process %d affinity is : ",pid);
        for(int i=0; i<CPU_SETSIZE; i++)
            if(CPU_ISSET(i,&mask))
                printf("CPU %d ",i);
        printf("\n");
    }
}

int main(){
    pid_t pid = getppid();
    printf("Initial CPU affinity : \n");
    get_cpu(pid);

    set_cpu(pid,5);
    printf("After affinity setting : \n");
    get_cpu(pid);
}