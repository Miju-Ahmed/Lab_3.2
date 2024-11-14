#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include <sys.h>
using namespace std;

int main(){
    pid_t childPprocess, parentPprocess;
    int signal=9;
    childPprocess = fork();
    if(childPprocess == 0){
        kill(getppid(),signal);
        cout<<"Child process"<<endl;
        cout<<"Parent Process terminated"<<endl;
    }
    else{
        kill(childPprocess, signal);
        cout<<"Parent process"<<endl;
        cout<<"Child process terminated"<<endl;

    }
    return 0;
}