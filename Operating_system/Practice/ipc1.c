#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<string.h>

int main(){
    FILE *rd;
    char b[1024];
    sprintf(b,"Miju Chowdhury");
    rd = popen("wc -w", "w");
    fwrite(b,sizeof(char),strlen(b),rd);
    pclose(rd);
}