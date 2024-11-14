#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <linux/prctl.h>
#include <iostream>
using namespace std;

int main() {
  cout<<"Parent process PID is : "<<getpid()<<endl;
    pid_t child_pid[3];
  for(int i=0; i<3; i++){
    child_pid[i] = fork();

    if(child_pid[i]==0){
        cout<<"child_"<<i+1<<" is : "<<getpid()<<endl;
        exit(0);
    }
    
  }

  return 0;
}
