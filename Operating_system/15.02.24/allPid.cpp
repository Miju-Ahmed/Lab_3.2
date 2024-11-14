#include<bits/stdc++.h>
using namespace std;
int main(){
    pid_t parent = getppid();
    pid_t current = getpid();
    pid_t child = fork();
    cout<<"Parent PID : "<<parent<<endl;
    cout<<"Current PID : "<<current<<endl;
    cout<<"Child PID : "<<child<<endl;
    return 0;
}
