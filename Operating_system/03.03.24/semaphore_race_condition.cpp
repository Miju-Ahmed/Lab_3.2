#include<bits/stdc++.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
using namespace std;

int x=0;
sem_t sem_key;

void* sum(void*){
    for(int i=0; i<200; i++){
        sem_wait(&sem_key);
        x  = x+1;
        printf("i : %d After summation : %d\n", i, x);
        sem_post(&sem_key);
    }
    return 0;
}

void * sub(void*){
    for(int j=0; j<200; j++){
        sem_wait(&sem_key);
        x = x-1;
        printf("j : %d After subtraction : %d\n",j,x);
        sem_post(&sem_key);
    }
    return 0;
}

int main(){
    sem_init(&sem_key, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1, NULL, sum, NULL);
    pthread_create(&t2, NULL, sub, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&sem_key);
    cout<<"Main thread will terminate now"<<endl;
    exit(EXIT_SUCCESS);
}