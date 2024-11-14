#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(){
    pid_t pid = fork();

    if(pid==0){
        cout<<"Child process pid : "<<getpid()<<" Its parent pid is : "<<getppid()<<endl;
    }
    else{
        cout<<"Parent wait for child process termaination."<<endl;
        wait(NULL);
        cout<<"Parent process pid : "<<pid<<endl;
    }
}