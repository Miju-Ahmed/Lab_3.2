#include<stdio.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    char *pp = "miju1";
    if(access(pp,F_OK)==0){
        printf("Pipe is already exists.\n");
    }
    else{
        int pf = mkfifo(pp,0666);
        if(pf==-1){
            printf("Error in creating pipe.\n");
        }
        else{
            printf("Pipe created successfully.\n");
        }
    }
    int fd = open(pp,O_RDWR);
    int send = 1;
    while(true){
        if(send){
            char b[1024];
            int n = read(STDIN_FILENO, b, 1024);
            b[n] = '\0';
            write(fd,b,strlen(b));
            if(b[0]=='b'&&b[1]=='y'&&b[2]=='e')
                return 0;
        }
        else{
            char b[1024];
            int  n = read(fd,b,1000);
            b[n] = '\0';
            write(STDOUT_FILENO,b,strlen(b));
            if(b[0]=='b'&&b[1]=='y'&&b[2]=='e'){
                return 0;
            }
        }
        send ^=1;
    }
}