#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>

int x=5,y=2;
int result=0;

int sum(){
    for(int i=0; i<300; i++){
        result = x+y;
        printf("i : %d  &   x+y : %d\n",i, x+y);
    }
}

int sub(){
    for(int j=0; j<300; j++){
        result = x-y;
        printf("j : %d  &   x-y : %d\n",j, x-y);
    }

}


int main(){
    // sum();
    // sub();
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL,(void*)sum,NULL);
    pthread_create(&tid2, NULL,(void*)sub,NULL);
    printf("%lu & %lu\n",tid1,tid2);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);


    exit(EXIT_SUCCESS);
}



