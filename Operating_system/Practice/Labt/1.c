#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

void addition(int a, int b) {
    printf("Child Process (Addition): %d + %d = %d\n", a, b, a + b);
}

void subtraction(int a, int b) {
    printf("Child Process (Subtraction): %d - %d = %d\n", a, b, a - b);
}

void multiplication(int a, int b) {
    printf("Child Process (Multiplication): %d * %d = %d\n", a, b, a * b);
}

int main() {
    pid_t pid1, pid2, pid3;
    int a = 10, b = 5; 
    
    pid1 = fork();
    if (pid1 == 0) {
        printf("Child 1 pid is %d\n",getpid());
        addition(a, b);
        exit(0);
    }
    pid2 = fork();
    if (pid2 == 0) {
        printf("Child 2 pid is %d\n",getpid());
        subtraction(a, b);
        exit(0); 
    }
    pid3 = fork();
    if (pid3 == 0) {
        printf("Child 3 pid is %d\n",getpid());
        multiplication(a, b);
        exit(0);
    }
    if (pid1 > 0 && pid2 > 0 && pid3 > 0) {
        wait(NULL);
        wait(NULL);
        wait(NULL);

        printf("Parent Process (Parent Process ID: %d)\n", getpid());
    }

    return 0;
}
