#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Signal handler function for SIGALRM
void sigalrm_handler(int signal) {
    printf("Alarm triggered! Time's up!\n");
    // Perform actions when the timer expires
}

int main() {
    // Set up signal handler for SIGALRM
    if (signal(SIGALRM, sigalrm_handler) == SIG_ERR) {
        perror("signal");
        return EXIT_FAILURE;
    }

    printf("Setting alarm for 10 seconds...\n");

    // Set an alarm for 5 seconds
    alarm(10);

    // Infinite loop to keep the program running
    while (1) {
        // Do nothing, just keep the program running
    }

    return EXIT_SUCCESS;
}
