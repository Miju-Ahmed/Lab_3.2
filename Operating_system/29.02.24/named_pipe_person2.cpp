#include<bits/stdc++.h>
#include<sys/stat.h>
#include <fcntl.h>
using namespace std;

int main(){
    char *pipePath = "/home/miju_chowdhury/Documents/Class-3.2/Operating System/Code/29.02.24/pipe";
    

    int pipe_id = open(pipePath, O_RDWR);
    if(pipe_id==-1){
        cout<<"Pipe path is not find"<<endl;
        return 1;
    }
    int send=0;
    while(true){
        if(send){
            char msg[1000];
            int msg_id = read(STDIN_FILENO, msg, 1000);
            if(msg_id==-1){
                cout<<"Could not input the message"<<endl;
                return 1;
            }
            msg[msg_id] = '\0';
            write(pipe_id,msg,strlen(msg));
            if(msg[0]=='b'&&msg[1]=='y'&&msg[2]=='e'){
                return 0;
            }
        }
        else{
            char msg[1000];
            int msg_id = read(pipe_id, msg, 1000);
            if(msg_id<0){
                cout<<"Could not input the message"<<endl;
                return 1;
            }
            msg[msg_id] = '\0';
            write(STDOUT_FILENO, msg,strlen(msg));
            if(msg[0]=='b'&&msg[1]=='y'&&msg[2]=='e'){
                return 0;
            }
        }
        send ^=1;
    }

}