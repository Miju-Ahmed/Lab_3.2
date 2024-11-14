#include<unistd.h>
#include<stdio.h>
#include<pthread.h>


int num[2]= {3,4};
int result=0;
int sub(void * n){
    // int result=0;
    int *x = n;
    for(int i=0; i<10; i++){
        result -= x[0] -x[1];
        printf("sub : %d\n",result);
    }
    pthread_exit("Subtraction calculated\n");
}
int sum(void * n){
    // int result=0;
    int *x = n;
    for(int i=0; i<10; i++){
        result += x[0] +x[1];
        printf("sum : %d\n",result);
    }
    pthread_exit("Sum calculated\n");
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,(void*)sum,(void*)num);
    pthread_create(&t2,NULL,(void*)sub,(void*)num);
    pthread_join(t1,&result);
    printf("Result sum : %s\n", (char*)result);
    pthread_join(t2,&result);
    printf("Result sub : %s\n", (char*) result);
}