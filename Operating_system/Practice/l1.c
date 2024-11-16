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
        perror("Pipe does not exist");
        return 1;
    }

    int fd = open(pp, O_RDWR);
    if (fd == -1) {
        perror("Error opening FIFO for reading");
        return 1;
    }

    int send = 0;
    while (true) {
         
        if (send) {
            char b[1024];
            int n = read(STDIN_FILENO, b, 1023);
            b[n] = '\0';
            write(fd, b, strlen(b)); // Write to FIFO
            if (strncmp(b, "bye", 3) == 0) {
                break;
            }
            
        }
        else {
            char b[1024];
            int n = read(fd, b, 1023);
            b[n] = '\0';
            write(STDOUT_FILENO, b, strlen(b)); 
            if (strncmp(b, "bye", 3) == 0) {
                break;
            }
            
        }
        send ^= 1;
    }

    close(fd);
    return 0;
}
