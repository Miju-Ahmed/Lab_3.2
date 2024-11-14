#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main(){
    int f,f1,n;
    char b[1024];
    f = open("seeking",O_RDWR);
    f1 = lseek(f,-11, SEEK_END);
    n = read(f,b,1024);
    write(1, b, n);
}