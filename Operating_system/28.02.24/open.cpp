#include<bits/stdc++.h>
#include <fcntl.h>
using namespace std;

int main(){
    int s = open("description.txt",O_WRONLY);
    cout<<s<<endl;
    //close(s);
    return 0;
}


// #include <iostream>
// #include <cstring>
// #include <unistd.h>
// #include <fcntl.h>
//
// using namespace std;
//
// int main() {
//     char *msg;
//     char buffer[100];
//     int n, c;
//     msg = "Insert a number: ";
//     write(STDOUT_FILENO, msg, strlen(msg));
//     n = read(STDIN_FILENO, &buffer, sizeof(buffer) - 1); // Make space for null terminator
//     if (n < 0) {
//         perror("Error reading from stdin");
//         return 1;
//     }
//     buffer[n] = '\0';
//
//     // Open file named "in" for writing
//     c = open("in", O_WRONLY); // Permission flags added
//     if (c < 0) {
//         perror("Error opening file");
//         return 1;
//     }
//
//     if (write(c, buffer, strlen(buffer)) < 0) {
//         perror("Error writing to file");
//         close(c); // Close the file descriptor before exiting
//         return 1;
//     }
//
//     close(c); // Close the file descriptor
//     return 0;
// }
