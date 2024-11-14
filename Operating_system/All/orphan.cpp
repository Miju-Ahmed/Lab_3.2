#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;
int main(){
    pid_t p = fork();
    if(p==0){
        sleep(10);
        cout<<"Child process pid "<<getpid()<<endl;
    }
    else{
        cout<<"Prent pid : "<<getpid()<<endl;
    }
}