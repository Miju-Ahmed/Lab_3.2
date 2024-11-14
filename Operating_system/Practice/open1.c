#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int fd,n,fd1;
    char b[1024];
    fd = open("t1.txt",O_RDONLY);
    n = read(fd,b,1024);
    fd1 = open("t2.txt",O_CREAT|O_WRONLY,0642);
    write(fd1,b,n);
    
}