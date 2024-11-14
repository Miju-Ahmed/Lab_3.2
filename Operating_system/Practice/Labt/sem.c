#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>


sem_t s;
int r = 1;

int f1(){
    sem_wait(&s);
    for(int i=0; i<1000; i++)
        r++;
    sem_post(&s);
}

int f2(){
    sem_wait(&s);
    for(int i=0; i<1000; i++)
        r--;
    sem_post(&s);
}

int main(){
    sem_init(&s, 0,1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)f1,NULL);
    pthread_create(&t2,NULL,(void*)f2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Result : %d\n",r);

}