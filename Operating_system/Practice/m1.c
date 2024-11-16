#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<stdbool.h>

int main() {
    char pp[] = "miju2";
    if (access(pp, F_OK) != 0) {
        if (mkfifo(pp, 0666) == -1) {
            perror("Error creating pipe");
            return 1;
        }
    }

    int fd = open(pp, O_RDWR);

    int send = 1;
    while (true) {
         
        if (send) {
            char b[1024];
            int n = read(STDIN_FILENO, b, 1023);
            b[n] = '\0';
            write(fd, b, strlen(b));
            if (strncmp(b, "bye", 3) == 0) 
                return 0;
        }
        else {
            char b[1024];
            int n = read(fd, b, 1023);
            b[n] = '\0';
            write(STDOUT_FILENO, b, strlen(b)); 
            if (strncmp(b, "bye", 3) == 0) 
                return 0;
        }
        send ^= 1;
    }

    close(fd);
    return 0;
}
