#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<sys/ipc.h>

sem_t k;

int main(){
    sem_init(&k,0,1);
    int shmid = shmget(IPC_PRIVATE,sizeof(int),IPC_CREAT|0666);
    if(shmid<0)
        printf("Error\n");
    int *data = (int*) shmat(shmid, NULL, 0);
    if(*data<0)
        printf("Error attaching shared memory.\n");
    
    *data = 10;
    pid_t p = fork();
    if(p==0){
        for(int i=0; i<10; i++){
            sem_wait(&k);
            *data = *data + 1;
            printf("Child : %d\n",*data);
            sem_post(&k);
        }
    }
    else{
         for(int i=0; i<10; i++){
            sem_wait(&k);
            *data = *data - 1;
            printf("Parent : %d\n",*data);
            sem_post(&k);
        }
        wait(NULL);
    }

    int st = shmdt(data);
    if(st<0)
        printf("Error deleting shm\n");
    st = sem_destroy(&k);
    if(st<0)
        printf("Error deleting sem\n");
    return 0;
}