#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/setsid.h>

int main() {
  pid_t child_pid = fork();

  if (child_pid == -1) {
    perror("fork failed");
    exit(1);
  } else if (child_pid == 0) {
    // Child process code
    // Detach from the parent process (becomes session leader)
    if (setsid() == -1) {
      perror("setsid failed");
      exit(1);
    }

    printf("Child process (PID: %d) - Orphaned!\n", getpid());

    // Simulate some work (optional)
    sleep(10);

    exit(0);
  } else {
    // Parent process code
    printf("Parent process (PID: %d) exiting.\n", getpid());
    exit(0);
  }
}
