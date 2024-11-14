#include<bits/stdc++.h>
#include<sys/wait.h>

using namespace std;

int main(){
    pid_t pid = fork();
    if(pid == 0){
        cout << "I am child process" << endl;
        cout<<"Child process exit"<< endl;
    }else{
        cout << "I am parent process" << endl;
        sleep(10);
        cout<<"Parent process exit"<< endl;
    }
}