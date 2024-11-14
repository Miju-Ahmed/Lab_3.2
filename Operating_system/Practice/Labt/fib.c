#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int f[10];

void* compute_fib(void *arg){
    int index = *(int*)arg;
    free(arg);

    if(index ==0)
        f[index]=0;
    else if(index==1)
        f[index]=1;
    else
        f[index] = f[index-1] + f[index-2];
}

int main(){
    pthread_t t[10];
    for(int i=0; i<10; i++){
        int* index = malloc(sizeof(int));
        *index = i;
        pthread_create(&t[i], NULL, compute_fib, index);

    }

    printf("Fibonacci sequence : ");
    for(int i=0; i<10; i++){
        printf("%d", f[i]);
    }
    printf("\n");
}