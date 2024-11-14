#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>

int main(){
    int n, fd, fd1;
    char b[1024];
    fd = open("seeking",O_RDWR);
    n = read(fd,b,10);
    write(1,b,n);
    printf("\n");
    lseek(fd,15,SEEK_CUR);
    n = read(fd,b,1024);
    write(1,b,n);
    
}