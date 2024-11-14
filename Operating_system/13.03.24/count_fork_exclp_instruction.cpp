#include<bits/stdc++.h>
using namespace std;

int main(int argc, char){
    pid_t childPID, parPID;
    for(int i=0; i<3; i++){
        fork();
        //cout<<"Its a process!"<<endl; //when we use it here the child process is printed two times
        
    }
    cout<<"Its a process!"<<endl; //when we use it here the child process is printed single time

    execlp("./hello","hello",NULL);
    cout<<"Hi"<<endl;   //Next instruction can't run
    return 0;
}