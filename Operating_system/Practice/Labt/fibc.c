#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10  // Number of Fibonacci numbers to generate

// Array to store Fibonacci sequence
int fibonacci_sequence[MAX];

// Function to be executed by each thread
void* compute_fibonacci(void* arg) {
    int index = *(int*)arg;
    free(arg);  // Free allocated memory

    // Compute Fibonacci number for the given index
    if (index == 0)
        fibonacci_sequence[index] = 0;
    else if (index == 1)
        fibonacci_sequence[index] = 1;
    else
        fibonacci_sequence[index] = fibonacci_sequence[index - 1] + fibonacci_sequence[index - 2];

    return NULL;
}

int main() {
    pthread_t threads[MAX];

    // Create threads for each Fibonacci index
    for (int i = 0; i < MAX; i++) {
        int* index = malloc(sizeof(int));  // Allocate memory for each index
        *index = i;  // Assign the index value
        pthread_create(&threads[i], NULL, compute_fibonacci, index);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the Fibonacci sequence
    printf("Fibonacci sequence: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", fibonacci_sequence[i]);
    }
    printf("\n");

    return 0;
}
