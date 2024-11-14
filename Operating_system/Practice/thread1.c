#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

int sum(int x){
    for(int i=0; i<10; i++){
        printf("i = %d \n", i);
        // sleep(1);
    }
    printf("\n");
}

int sub(int x){
    for(int i=0; i<10; i++){
        printf("j = %d \n",i);
        sleep(1);
    }
    printf("\n");
}

int main(){
    pthread_t t1,t2;

    pthread_create(&t1,NULL,(void*)sum,NULL);
    pthread_create(&t2,NULL,(void*)sub, NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}