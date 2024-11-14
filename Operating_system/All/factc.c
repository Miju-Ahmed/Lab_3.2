#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5  // Maximum number of threads

pthread_mutex_t mutex;  // Mutex for synchronizing access to shared variable
long long result = 1;   // Shared variable to store intermediate factorial results
int number = 10;        // Number for which to calculate factorial

// Thread function to compute part of the factorial
void* calculate_factorial(void* arg) {
    int start = *(int*)arg;
    int end = start + (number / MAX_THREADS);

    // Calculate partial factorial
    long long partial_result = 1;
    for (int i = start; i <= end; i++) {
        partial_result *= i;
    }

    // Lock mutex before updating shared variable
    pthread_mutex_lock(&mutex);
    result *= partial_result;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_args[MAX_THREADS];

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads
    for (int i = 0; i < MAX_THREADS; i++) {
        thread_args[i] = i * (number / MAX_THREADS) + 1;
        pthread_create(&threads[i], NULL, calculate_factorial, &thread_args[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    // Print result
    printf("Factorial of %d is %lld\n", number, result);

    return 0;
}
