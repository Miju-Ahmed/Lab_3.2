#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    int fd[2],n;
    pipe(fd);
    pid_t p =fork();
    char b[1025];
    if(p==0){
        close(fd[1]);
        n = read(fd[0],b,sizeof(b)+1);
        b[n]='\n';
        printf("Read from child : %s\n",b);
        close(fd[0]);
    }
    else{
        close(fd[0]);
        // scanf("%s",b);
        printf("Send from parent: ");
        fgets(b,sizeof(b),stdin);
        write(fd[1],b,sizeof(b));
        close(fd[1]);
    }
}