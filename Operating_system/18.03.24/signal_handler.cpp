#include <unistd.h>
#include <signal.h>
#include<bits/stdc++.h>
using namespace std;

void sigint_handler(int signal) {
    cout<<"Signal handle : "<<signal<<endl;
}

int main() {
    for(int i=1; i<=64; i++){
        signal(i, sigint_handler);
    }
    pid_t pid = getpid();
    cout<<pid<<endl;
    for(int i=1; i<=64; i++){
        if(i==9 || i==19 || i==32 || i==33)
            continue;
        kill(pid, i);
        usleep(1000);
    }
    return EXIT_SUCCESS;
}
