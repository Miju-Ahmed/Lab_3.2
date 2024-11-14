#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

int balance = 1000000;

int deposit(){
    for(int i=0; i<10000; i++){
        balance++;
    }
}
int withdraw(){
    for(int i=0; i<10000; i++){
        balance--;
    }
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1, NULL, (void*)deposit, NULL);
    pthread_create(&t2, NULL, (void*)withdraw, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Result : %d\n",balance);

    return 0;
}