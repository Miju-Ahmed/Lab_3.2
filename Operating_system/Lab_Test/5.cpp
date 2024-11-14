#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Check for valid arguments
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <number_of_children> <child_name1> ... <child_nameN>\n", argv[0]);
    exit(1);
  }

  // Get the number of child processes
  int num_children = atoi(argv[1]);

  // Create child processes with names
  for (int i = 0; i < num_children; i++) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
      perror("fork failed");
      exit(1);
    } else if (child_pid == 0) {
      // Child process code
      char new_name[16];
      sprintf(new_name, "%s_%d", argv[i + 2], i + 1);
      prctl(PR_SET_NAME, new_name); // Set process name (Linux specific)

      printf("Child %d (PID: %d; PPID: %d): %s\n", i + 1, getpid(), getppid(), new_name);
      exit(0);
    }
  }

  // Wait for all child processes to finish
  for (int i = 0; i < num_children; i++) {
    wait(NULL);
  }

  printf("Parent process exiting.\n");
  return 0;
}
