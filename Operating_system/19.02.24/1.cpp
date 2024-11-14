#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<iostream>
#include<sys/wait.h>
#include <newlib/sys/unistd.h>

using namespace std;
int main(){
    pid_t pid = fork();
    if(pid<0){
        fprintf(stderr,"Fork failed");
        return 1;
    }
    else if(pid==0){
        execlp("/bin/ls","ls",NULL);
    }
    else{
        wait(NULL);
        cout<<"Child Complete"<<endl;
    }
    return 0;
}
