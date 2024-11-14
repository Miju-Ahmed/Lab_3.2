#include<bits/stdc++.h>
using namespace std;

int main(){
    pid_t myPid, childPid,parentPid;
    myPid = getpid();
    childPid = fork();
    parentPid = getppid();
    cout<<"Parent Pid: "<<parentPid<<endl;;
    cout<<"My Pid : "<<myPid<<endl;
    cout<<"Child Pid : "<<childPid<<endl;
    return 0;

}
