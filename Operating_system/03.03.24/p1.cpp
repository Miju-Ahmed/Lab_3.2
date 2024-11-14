#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h> 
#include<bits/stdc++.h>
#include <semaphore.h> 
using namespace std;
key_t key = 11345;
sem_t sm;

int main() {
    sem_init(&sm, 0, 1);
    int shmid = shmget(key, sizeof(int)*3, IPC_CREAT | 0666);
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
    for(int i = 0; i < 10; i++){
        sem_wait(&sm);
        sleep(1);
        *myVar = *myVar + 1;
        cout << "P1: " << *myVar << endl;
        sem_post(&sm);
    }
    int st = shmdt(myVar);
    if(st < 0){
        cout << "Error detaching shared memory" << endl;
    }
    st = shmctl(shmid, IPC_RMID, NULL);
    if(st < 0){
        cout << "Error deleting shared memeory" << endl;
    }
    sem_destroy(&sm);
    return 0;
    
}
