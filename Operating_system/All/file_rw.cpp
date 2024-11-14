#include<bits/stdc++.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

using namespace std;

int main(){
    char b[1024];
    int n;
    int fd = open("t.txt",O_RDWR);
    n = read(STDIN_FILENO,b,1024);
    write(STDOUT_FILENO,b,n);
}