//This code connected with main.cpp, inject.cpp
#include<iostream>
#include<cstring>
#include<unistd.h>
#include <stdio.h>

int main(){
    char str[100] = "./ex";
    char input[5];
    
    scanf("%s", input);
    execlp(str,"miju",NULL);
    printf("%s\n", input);
}
