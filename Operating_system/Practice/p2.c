#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
 char input[100];
 int fd, num;
 mkfifo("/tmp/myfifo", 0666);
 while (1) {
 fd = open("/tmp/myfifo", O_RDONLY);
 // Read input from the FIFO
 read(fd, input, sizeof(input));
 close(fd);
 // Check if input is "Bye"
 if (strcmp(input, "Bye") == 0) {
 printf("Terminating...\n");
 break;
 }
 // Convert input to integer
 num = atoi(input);
 // Print countdown from n to 1
 for (int i = num; i > 0; i--) {
 printf("%d\n", i);
 sleep(1); // Adding sleep to simulate delay
 }
 }
 // Remove the named pipe
 unlink("/tmp/myfifo");
 return 0;
}
