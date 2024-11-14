#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

// Function to set CPU affinity
void set_cpu(pid_t pid, int cpu) {
    cpu_set_t mask;
    CPU_ZERO(&mask);          // Initialize the mask to zero
    CPU_SET(cpu, &mask);      // Set the mask to include the specified CPU

    if (sched_setaffinity(pid, sizeof(mask), &mask) == -1) {
        perror("sched_setaffinity failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Successfully set CPU affinity to CPU %d for process %d\n", cpu, pid);
    }
}

// Function to get CPU affinity
void get_cpu(pid_t pid) {
    cpu_set_t mask;
    CPU_ZERO(&mask);          // Initialize the mask to zero

    if (sched_getaffinity(pid, sizeof(mask), &mask) == -1) {
        perror("sched_getaffinity failed");
        exit(EXIT_FAILURE);
    } else {
        printf("Process %d affinity: ", pid);
        for (int i = 0; i < CPU_SETSIZE; i++) {
            if (CPU_ISSET(i, &mask)) {
                printf("CPU %d ", i);  // Print each CPU the process is allowed to run on
            }
        }
        printf("\n");
    }
}

int main() {
    pid_t pid = getpid();  // Get the current process ID

    printf("Initial CPU affinity:\n");
    get_cpu(pid);          // Display the initial CPU affinity

    set_cpu(pid, 1);       // Set CPU affinity to CPU 1

    printf("CPU affinity after setting:\n");
    get_cpu(pid);          // Display the updated CPU affinity

    return 0;
}
