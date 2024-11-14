#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>

void get_niceness_and_priority(pid_t pid) {
    errno = 0; // Clear errno before calling getpriority

    // Get the current niceness value (priority level)
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority failed");
    } else {
        printf("Current priority (niceness) of process %d: %d\n", pid, priority);
    }
}

void set_niceness(pid_t pid, int nice_value) {
    if (setpriority(PRIO_PROCESS, pid, nice_value) == -1) {
        perror("setpriority failed");
    } else {
        printf("Successfully set new niceness (priority) to %d for process %d\n", nice_value, pid);
    }
}

int main() {
    pid_t pid = getpid();  // Get the current process ID

    // Display the initial niceness value and priority
    printf("Initial niceness and priority:\n");
    get_niceness_and_priority(pid);

    // Set a new niceness value
    int new_nice_value = 10;
    printf("\nSetting new niceness to %d...\n", new_nice_value);
    set_niceness(pid, new_nice_value);

    // Display the updated niceness value and priority
    printf("\nUpdated niceness and priority:\n");
    get_niceness_and_priority(pid);

    return 0;
}
