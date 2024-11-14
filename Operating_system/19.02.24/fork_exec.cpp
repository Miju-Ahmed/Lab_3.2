#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    pid_t pid = fork();
    string st = "";
    cin>>st;
    if(pid<0){
        fprintf(stderr,"Fork Failed.");
        return 1;
    }
    else if(pid==0)
            execlp("/bin/ls","ls",NULL);
    else{
        wait(NULL);
        printf("Child complete");
    }
    int status;
    pid_t pidSt = wait(&status);
    printf("\nPid status %d\n",pidSt);
    return 0;
}
