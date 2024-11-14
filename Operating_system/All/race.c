#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
int x = 1;
int f1(){
    for(int i=0;i<10000; i++)
        x++;
}
int f2(){
    for(int i=0; i<10000; i++)
        x--;
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)f1,NULL);
    pthread_create(&t2,NULL,(void*)f2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Result : %d\n",x);
}