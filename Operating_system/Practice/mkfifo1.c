#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int fd;
    fd = mkfifo("fifo2",0777);
    printf("second Fifo is created");
}