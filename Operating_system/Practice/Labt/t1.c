#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


int f1(){
    printf("Hello world.\n");
}

int f2(){
    int a=4,b=5;
    printf("Sub = %d\n",a-b);
}

int main(){
    fork();
    execlp("/bin/ls","ls",NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)f1,NULL);
    pthread_create(&t2,NULL,(void*)f2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

}