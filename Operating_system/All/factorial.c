#include<stdio.h>
#include<pthread.h>

pthread_mutex_t m;
long long r = 1;
int n,tn;

void* fact(void* arg){
    int start = *(int*)arg;
    int end = start + (n/tn);

    long long pr = 1;
    for(int i= start; i<=end; i++)
        pr += i;
    pthread_mutex_lock(&m);
    r *= pr;
    pthread_mutex_unlock(&m);
    return NULL;
}

int main(){
    printf("Enter the number of threads and the number : ");
    scanf("%d %d",&tn,&n);
    pthread_t t[tn];
    int tv[tn];
    pthread_mutex_init(&m,NULL);
    for(int i=0; i<tn; i++){
        tv[i] = i*(n/tn)+1;
        pthread_create(&t[i],NULL,fact,&tv[i]);
    }
    for(int i=0; i<tn; i++)
        pthread_join(t[i],NULL);
    pthread_mutex_destroy(&m);
    printf("Factorial of %d is %lld\n",n,r);
    return 0;
}