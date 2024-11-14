#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getppid();
    printf("My process ID is: %d\n", pid);
    return 0;
}

