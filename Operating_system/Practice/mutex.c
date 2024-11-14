#include<unistd.h>
#include<pthread.h>
#include<stdio.h>

pthread_mutex_t l;
int s=1;

int f1();
int f2();

int main(){
    pthread_mutex_init(&l,NULL);

    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)f1,NULL);
    pthread_create(&t2,NULL,(void*)f2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("Final value : %d\n",s);
}

int f1(){
    pthread_mutex_lock(&l);
    s+=100;
    printf("increase : %d\n",s);
    pthread_mutex_unlock(&l);
}

int f2(){
    pthread_mutex_lock(&l);
    s-=100;
    printf("decrese : %d\n",s);
    pthread_mutex_unlock(&l);
}