#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
    int fd[2],n;
    pipe(fd);
    pid_t p = fork();
    if(p==0){
        close(fd[1]);
        char b[1024];
        n = read(fd[0], b, 1024);
        b[n] = '\n';
        printf("Read form child: %s\n",b);
        close(fd[0]);
    }
    else{
        close(fd[0]);
        char b[1024];
        printf("Send from parents: ");
        fgets(b,sizeof(b),stdin);
        write(fd[1],b,sizeof(b));
        close(fd[1]);
    }
}