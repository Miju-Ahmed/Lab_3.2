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
    n = read(0,b,sizeof(b));
    write(1,b,n);
}