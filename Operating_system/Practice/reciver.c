#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int fd,n;
    char b[1024];
    fd = open("fifo1", O_RDONLY);
    n = read(fd, b, 1024);
    printf("Reader pid is %d\n",getpid());
    printf("Data receiver by the reciver pid %d is : %s\n", getpid(),b);
}