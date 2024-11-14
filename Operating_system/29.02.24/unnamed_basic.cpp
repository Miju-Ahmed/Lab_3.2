#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<iostream>

using namespace std;

int main(){
    int data[2];

    if(pipe(data)==-1){
        cout<<"Unnamed pipe is not created."<<endl;
        return 1;
    }

    pid_t pid = fork();
    if(pid==0){
        close(data[1]);
        char buffer[100];
        ssize_t bytes_Read = read(data[0],buffer, size(buffer));
        if(bytes_Read)
    }
}