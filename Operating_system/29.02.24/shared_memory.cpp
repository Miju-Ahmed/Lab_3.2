#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include<bits/stdc++.h>
#include<sys/wait.h>

using namespace std;

// Structure for the shared data
struct SharedData {
    int value;
    char message[100];
};

int main() {
    const char* sharedMemoryName = "/my_shared_memory";
    int shm_fd = shm_open(sharedMemoryName, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        cerr << "Error opening shared memory" << endl;
        exit(EXIT_FAILURE);
    }

    // Set the size of the shared memory segment
    ftruncate(shm_fd, sizeof(SharedData));

    // Map the shared memory segment into the address space of this process
    SharedData* sharedData = (SharedData*)mmap(NULL, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (sharedData == MAP_FAILED) {
        cerr << "Error mapping shared memory" << endl;
        exit(EXIT_FAILURE);
    }

    // Write data into the shared memory
    sharedData->value = 42;
    strcpy(sharedData->message, "Hello from the writer process!");

    // Fork a new process
    pid_t pid = fork();

    if (pid == -1) {
        cerr << "Error forking process" << endl;
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process reads data from shared memory
        cout << "Child process: Value = " << sharedData->value << ", Message = " << sharedData->message << endl;
    } else {
        // Parent process waits for the child to finish
        wait(NULL);
    }

    // Unmap and close the shared memory segment
    munmap(sharedData, sizeof(SharedData));
    close(shm_fd);

    // Unlink the shared memory object
    shm_unlink(sharedMemoryName);

    return 0;
}
