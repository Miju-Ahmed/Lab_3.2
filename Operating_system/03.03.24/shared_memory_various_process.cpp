#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<unistd.h>
#include<semaphore.h>
#include<bits/stdc++.h>
using namespace std;

sem_t key;

int main(){
    sem_init(&key, 0,1);
    int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if(shmid<0){
        cout<<"Error creating sharem memory"<<endl;
        return 1;
    }
    int * data = (int*) shmat(shmid, NULL, 0);
    if(*data<0){
        cout<<"Error attaching shared memory"<<endl;
        return 1;
    }
    *data = 0;
    pid_t pid = fork();
    if(pid==0){
        for(int i=0; i<10; i++){
            sem_wait(&key);
            *data = *data + 1;
            cout<<"Child : "<<*data<<endl;
            sem_post(&key);
        }
    }
    else{
        for(int i=0; i<10; i++){
            sem_wait(&key);
            *data = *data -1;
            cout<<"Parent : "<<*data<<endl;
            sem_post(&key);
        }
        wait(NULL);
    }

    int st = shmdt(data);
    if(st<0){
        cout<<"Error deleting shared memory"<<endl;
    }
    st = sem_destroy(&key);
    if(st<0){
        cout<<"Error deleting semaphore"<<endl;
    }
    return 0;
}