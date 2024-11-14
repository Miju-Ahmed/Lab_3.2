#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    int res, n;
    res = open("fifo1", O_WRONLY);
    write(res, "message", 7);
    printf("Sender process pid is %d\n",getpid());
}