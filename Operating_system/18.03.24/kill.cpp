//This code connected with signal_kill.cpp
#include <iostream>
#include <signal.h>
using namespace std;

//9,19,32,33
int main() {
    int pid ,signal;
    cin>>pid;

    for(int i=1; i<=64; i++){
        cin>>signal;
        kill(pid,signal);
    }
}
