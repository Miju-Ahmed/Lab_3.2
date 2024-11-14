#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void create_child_process(const char *child_name) {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        char *args[] = {"sh", "-c", "echo $PPID", NULL};
        FILE *file = fopen("process_log.txt", "a");
        if (file != NULL) {
            fprintf(file, "Child process %s with PID %d created.\n", child_name, getpid());
            fclose(file);
        }
        printf("%s (PID: %d) is created.\n", child_name, getpid());
        sleep(5);

        exit(0);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number of children> <child names>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0 || argc != n + 2) {
        printf("Invalid number of child processes or incorrect arguments.\n");
        return 1;
    }

    printf("Parent process PID: %d\n", getpid());
    for (int i = 2; i < argc; i++) {
        create_child_process(argv[i]);
    }
    for (int i = 2; i < argc; i++) {
        sleep(5);
    }
    printf("\nTracing process tree:\n");
    system("pstree -p");

    return 0;
}
