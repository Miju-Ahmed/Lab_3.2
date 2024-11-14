#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdbool.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int pf;
    char *pp = "miju";
    if(access(pp,F_OK)==0)
        printf("pipe already exists.\n");
    else
        pf = mkfifo(pp, 0666);
    
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
            int n = read(fd,b,1024);
            b[n]='\0';
            write(STDOUT_FILENO,b,strlen(b));
            if(b[0]=='b'&&b[1]=='y'&&b[2]=='e')
                return 0;
        }
        send ^=1;
    }
}