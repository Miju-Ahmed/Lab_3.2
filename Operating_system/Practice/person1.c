#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd,n;
    char b[1024];
    fd = open("fifo2",O_RDWR);
    pid_t p = fork();

    char msg[1024];
    int s=0;
    while(s==0){
        if(p==0){
            scanf("S : %s", msg);
            write(fd,msg,sizeof(msg));
        }else{
            read(fd, b, sizeof(b));
            printf("S : %s",b);
        }
    }

}