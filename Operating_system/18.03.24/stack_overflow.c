#include <stdio.h>

int main(){
    
    char sstr[100] = "University of Rajshahi";
    char fstr[5];
    // fstr[0] = 'B';

    for(int i=0; i<10; i++){
        fstr[i] = 'A';
    }
    fstr[4] = '\0';
    printf("F: %s\n", fstr);
    printf("S: %s\n", sstr);

    printf("%u\n", &fstr[0]);
    printf("%u\n", &sstr[0]);
    return 0;
}
