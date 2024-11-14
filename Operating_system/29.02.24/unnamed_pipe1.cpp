#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#include <string.h>

using namespace std;

int main(){
    int pipefd[2];

    if(pipe(pipefd)==-1){
        cerr<<"Error creating pipe"<<endl;
        return 1;
    }

    pid_t pid = fork();

    if(pid == -1){
        cerr<<"Error forking process"<<endl;
        return 1;
    }
    else if(pid==0){
        close(pipefd[1]);

        char buffer[100];
        ssize_t bytesRead = read(pipefd[0], buffer, sizeof(buffer));
        if(bytesRead == -1){
            cerr<<"Error reading from pipe"<<endl;
            return 1;
        }
        buffer[bytesRead]='\0';
        cout<<"Child process received : "<<buffer<<endl;
        close(pipefd[0]);
    }
    else{
        close(pipefd[0]);

        const char* message = "Hello from the parent process";
        ssize_t bytesWritten = write(pipefd[1], message, strlen(message));
        if(bytesWritten == -1){
            cerr<<"Error writing to pipe"<<endl;
            return 1;
        }

        close(pipefd[1]);
        wait(NULL);
    }
    return 0;
}