#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;

int main(){
    pid_t p = fork();
    if(p==0)
        cout<<"child pid "<<getpid()<<" parent pid "<<getppid()<<endl;
    else{
        wait(NULL);
        sleep(10);
        cout<<"parent pid "<<getpid()<<endl;
    }
}