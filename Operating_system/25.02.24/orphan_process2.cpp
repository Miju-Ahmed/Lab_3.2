#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>

using namespace std;

int main(){
    pid_t childPid = fork();
    pid_t myPid;

    if(childPid<0){
        cout<<"Child Pid is not created."<<endl;
        exit(EXIT_FAILURE);
    }
    else if(childPid==0){
        for(int i=0; ; i++){
            cout<<"Child : "<<i<<" parent id: "<<getppid()<<" Child Id: "<<getpid()<<endl;
        }
        //sleep(10);
        //cout<<"Child"<<endl;
        //cout<<"Created Childs Parent Pid is : "<<getpid()<<endl;
         //cout<<"Created Childs Parent Pid is : "<<getpid()<<endl;
         //cout<<"Childs Parent "<<getppid()<<endl;
        //sleep(1);
        exit(EXIT_SUCCESS);
    }
    else{
        //sleep(10);
        for(int i=0; i<100000; i++){
            cout<<"Parent : "<<i<<" Parent Id : "<<getpid()<<endl;
        //cout<<"Parent process's Parent process is "<<getppid()<<endl;
        //cout<<"Current pid is "<<getpid()<<endl;
        }
        exit(EXIT_SUCCESS);
    }
    cout<<childPid<<endl;

}
