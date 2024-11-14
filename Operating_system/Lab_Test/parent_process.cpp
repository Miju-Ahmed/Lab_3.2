#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  printf("I am the parent_process, my PID: %d\n", getpid());

  for (int i = 0; i < 3; i++) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
      perror("fork failed");
      exit(1);
    } else if (child_pid == 0) {
      printf("Child %d: PID: %d; PPID: %d\n", i + 1, getpid(), getppid());
      exit(0);
    }
  }
  for (int i = 0; i < 3; i++) {
    wait(NULL);
  }

  printf("Parent process exiting.\n");
  return 0;
}
