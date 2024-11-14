#include<unistd.h>
#include<stdio.h>

int main(){
    char b[1024];
    int n = read(0, b, 1024);
    write(1, b, n);
}