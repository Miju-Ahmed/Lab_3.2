#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
 char input[100];
 int fd;
 // Create named pipe
 mkfifo("/tmp/myfifo", 0666);
 while (1) {
 // Open FIFO in write mode
 fd = open("/tmp/myfifo", O_WRONLY);
 // Get input from the user
 printf("Enter a number or 'Bye': ");
 fgets(input, 100, stdin);
 input[strcspn(input, "\n")] = '\0'; // Remove newline character
 // Write input to the FIFO
 write(fd, input, strlen(input) + 1);
 close(fd);
 // If input is "Bye", exit loop
 if (strcmp(input, "Bye") == 0) {
 break;
 }
 }
 // Remove the named pipe
 unlink("/tmp/myfifo");
 return 0;
}
