#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t r1;
sem_t r2;

void *f1(){
    printf("Process 1 trying to aquire resource r1\n");
    sem_wait(&r1);
    printf("Process 1 acquired resource r1\n");
    sleep(1);
    printf("Process 1 trying to aquire resource r2\n");
    sem_wait(&r2);
    printf("Process 1 acquired resource r2\n");
    sem_post(&r2);
    sem_post(&r1);
}

void* f2(){
    printf("Process 2 trying to acquire resource r2\n");
    sem_wait(&r2);
    printf("Process 2 acquired resource r2\n");
    sleep(1);
    printf("Process 2 trying to aquire resource r1\n");
    sem_wait(&r1);
    sem_post(&r1);
    sem_wait(&r2);
}

int main(){
    sem_init(&r1,0,1);
    sem_init(&r2,0,1);
    pthread_t t1, t2;
    pthread_create(&t1,NULL,f1,NULL);
    pthread_create(&t2,NULL,f2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&r1);
    sem_destroy(&r2);
    
}