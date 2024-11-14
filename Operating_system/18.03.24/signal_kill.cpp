//This code connected with kill.cpp
#include <unistd.h>
#include <signal.h>
#include<bits/stdc++.h>
using namespace std;


void sigint_handler(int signal) {
    cout<<"I have handle signal "<<signal<<endl;
    cout<<"But exiting with "<<" 10"<<endl;
    exit(10);
}

int main() {
    for(int i=1; i<=64; i++){
        signal(i, sigint_handler);
    }
    pid_t pid = getpid();
    cout<<pid<<endl;
    string a;   cin>>a;
    cout<<"This is the end of the program"<<endl;
    

    return EXIT_SUCCESS;
}
