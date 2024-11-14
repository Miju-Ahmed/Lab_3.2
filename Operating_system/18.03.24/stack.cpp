#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    // char str[4], *str1;
    // int i, len;
    // len = sizeof(str);
    // strcpy(str1, str);
    // for(int i=0; i<len; i++) {
    //     str[i] = 'a';
    // }
    // cout << str << endl;
    // cout<<str1 << endl;

    char s1[5], s2[100];
    for(int j=0; j<1000; j++){
        s2[j]='b';
    }
    for(int i=0; i<10; i++){
        s1[i] = 'a';
    }
    

    printf("%s\n", s1);
    printf("%s\n", s2);
    return 0;
}