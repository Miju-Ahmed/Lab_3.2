#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    int n, fd;
    char b[1024];
    int fd1 = open("t1.txt",O_RDONLY);
    n = read(fd1, b, 1024);
    fd = open("seeking", O_CREAT|O_WRONLY, 0666);
    write(fd,b,n);

}