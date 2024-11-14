#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

int s = 1;
int sum(){
    int x = s;
    printf("t1 : %d\n", x);
    x++;
    printf("t1 update : %d\n", x);
    sleep(1);
    s = x;
    printf("shre t1 : %d\n", s);
}
int sub(){
    int x = s;
    printf("t2 : %d\n", x);
    x--;
    printf("t2 update : %d\n", x);
    sleep(1);
    s = x;
    printf("shre t2 : %d\n", s);
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1, NULL, (void*)sum, NULL);
    pthread_create(&t2, NULL, (void*)sub, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("The final value of s is: %d\n", s);
}