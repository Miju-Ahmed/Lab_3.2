#include<bits/stdc++.h>
#include <fcntl.h>
using namespace std;

int main(){
    char *msg;
    char buffer[100];
    int n,c;
    msg = "Insert a number: ";
    write(STDOUT_FILENO, msg, strlen(msg)+1);
    n = read(STDIN_FILENO, &buffer, sizeof(buffer));
    buffer[n] = '\0';
    write(STDIN_FILENO, buffer, strlen(buffer));
    int id = open("description.txt",O_RDWR);
    cout<<id<<endl;
    msg = "Write in the file.";
    n = read(STDIN_FILENO, &buffer, sizeof(buffer));
    
}