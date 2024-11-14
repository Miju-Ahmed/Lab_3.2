#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;    
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;      

int shared_data = 0;                                  
int data_ready = 0;                                   

void* producer(void* arg) {
    pthread_mutex_lock(&mutex);
    shared_data = 42;
    printf("Producer: produced data %d\n", shared_data);
    
    data_ready = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

void* consumer(void* arg) {
    pthread_mutex_lock(&mutex);
    while (!data_ready) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Consumer: consumed data %d\n", shared_data);
    
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;
    
    if (pthread_create(&producer_thread, NULL, producer, NULL) != 0) {
        perror("Failed to create producer thread");
        exit(EXIT_FAILURE);
    }
    
    if (pthread_create(&consumer_thread, NULL, consumer, NULL) != 0) {
        perror("Failed to create consumer thread");
        exit(EXIT_FAILURE);
    }
    
    if (pthread_join(producer_thread, NULL) != 0) {
        perror("Failed to join producer thread");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(consumer_thread, NULL) != 0) {
        perror("Failed to join consumer thread");
        exit(EXIT_FAILURE);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    
    return 0;
}
