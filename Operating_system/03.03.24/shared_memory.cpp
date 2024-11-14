#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h> 
#include<bits/stdc++.h>
#include <semaphore.h> 
using namespace std;

sem_t key;

int main() {
    sem_init(&key, 1, 1);
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if(shmid < 0){
        cout << "Error creating shared memory" << endl;
        return 1;
    }
    int* myVar = (int*)shmat(shmid, NULL, 0);
    if(*myVar < 0){
        cout << "Error attaching shared memory" << endl;
        return 1;
    }
    *myVar = 0;
    pid_t pid = fork();
    if(pid == 0){
        for(int i = 0; i < 10; i++){
            sem_wait(&key);
            *myVar = *myVar + 1;
            cout << "Child: " << *myVar << endl;
            sem_post(&key);
        }
    }
    else{
        for(int i = 0; i < 10; i++){
            sem_wait(&key);
            *myVar = *myVar - 1;
            cout << "Parent: " << *myVar << endl;
            sem_post(&key);
        }
        wait(NULL);
    }

    int st = shmdt(myVar);
    if(st < 0){
        cout << "Error deleting shared memory" << endl;
    }
    st = sem_destroy(&key);
    if(st < 0){
        cout << "Error deleting semaphore" << endl;
    }
    return 0;
}
