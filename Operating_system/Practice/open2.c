#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main(){
    int fd,n;
    char b[1024];
    n = read(0, b, 1024);
    // fd = open("t1.txt", O_WRONLY);
    fd = open("t1.txt", O_WRONLY | O_APPEND);
    write(fd, b, n);
}