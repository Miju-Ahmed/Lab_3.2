#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
    int n,f,f1, s=1024;
    char b[1024];
    f = open("t1.txt", O_RDONLY);
    n = read(f, b, 1024);
    f1 = open("dup", O_CREAT|O_WRONLY, 0666);
    write(f1,b,n);

}