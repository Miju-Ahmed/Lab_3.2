#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
    int n,f,f1, s=1024;
    char b[1024];
    f = open("dup", O_RDONLY);
    n = read(f, b, 1024);
    printf("OLD file descriptor : %d\n", f);
    write(1,b,n);
    f1 = dup(f);
    printf("NEW file descriptor : %d\n", f1);
    int f2 = dup2(f,7);
    printf("dup2 file descriptor : %d\n", f2);
}