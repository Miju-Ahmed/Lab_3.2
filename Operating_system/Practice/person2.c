#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd = open("fifo2",O_RDWR);
    int n;
    char b[1024];
    pid_t p = fork();
    int s = 1;
    char msg[1024];
    while(s==1){
        if(p==0){
            n = read(fd, b, sizeof(b));
            printf("R : %s\n",b);
        }
        else{
            scanf("%s",msg);
            write(fd, msg, sizeof(msg));
        }
    }
}