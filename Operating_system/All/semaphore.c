#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<semaphore.h>

int x;
sem_t s;

int f(void *x){
    int n = *(int*)x;
    sem_wait(&s);
    printf("t[%d] is aquired the resource .\n",n);
    sleep(1);
    sem_post(&s);
    printf("t[%d] finished.\n",n);
}

int main(){
    sem_init(&s,0,3);
    int num;
    printf("Enter the number of thread: ");
    scanf("%d",&num);
    pthread_t t[num];
    for(int i=0; i<num; i++)
        pthread_create(&t[i],NULL,(void*)f,&i);
    for(int i=0; i<num; i++)
        pthread_join(t[i],NULL);
}